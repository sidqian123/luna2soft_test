/*	$NetBSD: i915_gem_phys.c,v 1.8 2021/12/19 12:45:43 riastradh Exp $	*/

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright © 2014-2016 Intel Corporation
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: i915_gem_phys.c,v 1.8 2021/12/19 12:45:43 riastradh Exp $");

#include <linux/highmem.h>
#include <linux/shmem_fs.h>
#include <linux/swap.h>

#include <drm/drm.h> /* for drm_legacy.h! */
#include <drm/drm_cache.h>
#include <drm/drm_legacy.h> /* for drm_pci.h! */
#include <drm/drm_pci.h>

#include "gt/intel_gt.h"
#include "i915_drv.h"
#include "i915_gem_object.h"
#include "i915_gem_region.h"
#include "i915_scatterlist.h"

#include <linux/nbsd-namespace.h>

static int i915_gem_object_get_pages_phys(struct drm_i915_gem_object *obj)
{
#ifdef __NetBSD__
	struct uvm_object *mapping = obj->base.filp;
#else
	struct address_space *mapping = obj->base.filp->f_mapping;
#endif
	struct scatterlist *sg;
	struct sg_table *st;
	dma_addr_t dma;
	void *vaddr;
	void *dst;
	int i;

	if (WARN_ON(i915_gem_object_needs_bit17_swizzle(obj)))
		return -EINVAL;


	/*
	 * Always aligning to the object size, allows a single allocation
	 * to handle all possible callers, and given typical object sizes,
	 * the alignment of the buddy allocation will naturally match.
	 */
#ifdef __NetBSD__
	__USE(dma);
	bus_dma_tag_t dmat = obj->base.dev->dmat;
	bool loaded = false;
	int rsegs = 0;
	int ret;

	vaddr = NULL;

	/* XXX errno NetBSD->Linux */
	ret = -bus_dmamem_alloc(dmat, roundup_pow_of_two(obj->base.size),
	    roundup_pow_of_two(obj->base.size), 0, &obj->mm.u.phys.seg, 1,
	    &rsegs, BUS_DMA_WAITOK);
	if (ret)
		return -ENOMEM;
	KASSERT(rsegs == 1);
	ret = -bus_dmamem_map(dmat, &obj->mm.u.phys.seg, 1,
	    roundup_pow_of_two(obj->base.size), &vaddr,
	    BUS_DMA_WAITOK|BUS_DMA_COHERENT);
	if (ret)
		goto err_pci;
	obj->mm.u.phys.kva = vaddr;
#else
	vaddr = dma_alloc_coherent(&obj->base.dev->pdev->dev,
				   roundup_pow_of_two(obj->base.size),
				   &dma, GFP_KERNEL);
	if (!vaddr)
		return -ENOMEM;
#endif

	st = kmalloc(sizeof(*st), GFP_KERNEL);
	if (!st)
		goto err_pci;

	if (sg_alloc_table(st, 1, GFP_KERNEL))
		goto err_st;

	sg = st->sgl;
#ifdef __NetBSD__
	/* XXX errno NetBSD->Linux */
	ret = -bus_dmamap_create(dmat, roundup_pow_of_two(obj->base.size), 1,
	    roundup_pow_of_two(obj->base.size), 0, BUS_DMA_WAITOK,
	    &sg->sg_dmamap);
	if (ret) {
		sg->sg_dmamap = NULL;
		goto err_st1;
	}
	sg->sg_dmat = dmat;
	/* XXX errno NetBSD->Linux */
	ret = -bus_dmamap_load_raw(dmat, sg->sg_dmamap, &obj->mm.u.phys.seg, 1,
	    roundup_pow_of_two(obj->base.size), BUS_DMA_WAITOK);
	if (ret)
		goto err_st1;
	loaded = true;
#else
	sg->offset = 0;
	sg->length = obj->base.size;

	sg_assign_page(sg, (struct page *)vaddr);
	sg_dma_address(sg) = dma;
	sg_dma_len(sg) = obj->base.size;
#endif

	dst = vaddr;
	for (i = 0; i < obj->base.size / PAGE_SIZE; i++) {
		struct page *page;
		void *src;

		page = shmem_read_mapping_page(mapping, i);
		if (IS_ERR(page))
			goto err_st;

		src = kmap_atomic(page);
		memcpy(dst, src, PAGE_SIZE);
		drm_clflush_virt_range(dst, PAGE_SIZE);
		kunmap_atomic(src);

#ifdef __NetBSD__
		uvm_obj_unwirepages(mapping, i*PAGE_SIZE, (i + 1)*PAGE_SIZE);
#else
		put_page(page);
#endif
		dst += PAGE_SIZE;
	}

	intel_gt_chipset_flush(&to_i915(obj->base.dev)->gt);

	__i915_gem_object_set_pages(obj, st, obj->base.size);

	return 0;

#ifdef __NetBSD__
err_st1:
	if (loaded)
		bus_dmamap_unload(dmat, st->sgl->sg_dmamap);
	sg_free_table(st);
#endif
err_st:
	kfree(st);
err_pci:
#ifdef __NetBSD__
	if (vaddr) {
		bus_dmamem_unmap(dmat, vaddr,
		    roundup_pow_of_two(obj->base.size));
	}
	obj->mm.u.phys.kva = NULL;
	if (rsegs)
		bus_dmamem_free(dmat, &obj->mm.u.phys.seg, rsegs);
#else
	dma_free_coherent(&obj->base.dev->pdev->dev,
			  roundup_pow_of_two(obj->base.size),
			  vaddr, dma);
#endif
	return -ENOMEM;
}

static void
i915_gem_object_put_pages_phys(struct drm_i915_gem_object *obj,
			       struct sg_table *pages)
{
#ifdef __NetBSD__
	bus_dma_tag_t dmat = obj->base.dev->dmat;
	void *vaddr = obj->mm.u.phys.kva;
#else
	dma_addr_t dma = sg_dma_address(pages->sgl);
	void *vaddr = sg_page(pages->sgl);
#endif

	__i915_gem_object_release_shmem(obj, pages, false);

	if (obj->mm.dirty) {
#ifdef __NetBSD__
		struct uvm_object *mapping = obj->base.filp;
#else
		struct address_space *mapping = obj->base.filp->f_mapping;
#endif
		void *src = vaddr;
		int i;

		for (i = 0; i < obj->base.size / PAGE_SIZE; i++) {
			struct page *page;
			char *dst;

			page = shmem_read_mapping_page(mapping, i);
			if (IS_ERR(page))
				continue;

			dst = kmap_atomic(page);
			drm_clflush_virt_range(src, PAGE_SIZE);
			memcpy(dst, src, PAGE_SIZE);
			kunmap_atomic(dst);

			set_page_dirty(page);
#ifdef __NetBSD__
			/* XXX mark_page_accessed */
			uvm_obj_unwirepages(mapping, i*PAGE_SIZE,
			    (i + 1)*PAGE_SIZE);
#else
			if (obj->mm.madv == I915_MADV_WILLNEED)
				mark_page_accessed(page);
			put_page(page);
#endif

			src += PAGE_SIZE;
		}
		obj->mm.dirty = false;
	}

#ifdef __NetBSD__
	bus_dmamap_unload(dmat, pages->sgl->sg_dmamap);
#endif

	sg_free_table(pages);
	kfree(pages);

#ifdef __NetBSD__
	bus_dmamem_unmap(dmat, obj->mm.u.phys.kva,
	    roundup_pow_of_two(obj->base.size));
	obj->mm.u.phys.kva = NULL;
	bus_dmamem_free(dmat, &obj->mm.u.phys.seg, 1);
#else
	dma_free_coherent(&obj->base.dev->pdev->dev,
			  roundup_pow_of_two(obj->base.size),
			  vaddr, dma);
#endif
}

static void phys_release(struct drm_i915_gem_object *obj)
{
#ifdef __NetBSD__
	/* XXX Who acquires the reference?  */
	uao_detach(obj->base.filp);
#else
	fput(obj->base.filp);
#endif
}

static const struct drm_i915_gem_object_ops i915_gem_phys_ops = {
	.get_pages = i915_gem_object_get_pages_phys,
	.put_pages = i915_gem_object_put_pages_phys,

	.release = phys_release,
};

int i915_gem_object_attach_phys(struct drm_i915_gem_object *obj, int align)
{
	struct sg_table *pages;
	int err;

	if (align > obj->base.size)
		return -EINVAL;

	if (obj->ops == &i915_gem_phys_ops)
		return 0;

	if (obj->ops != &i915_gem_shmem_ops)
		return -EINVAL;

	err = i915_gem_object_unbind(obj, I915_GEM_OBJECT_UNBIND_ACTIVE);
	if (err)
		return err;

	mutex_lock_nested(&obj->mm.lock, I915_MM_GET_PAGES);

	if (obj->mm.madv != I915_MADV_WILLNEED) {
		err = -EFAULT;
		goto err_unlock;
	}

	if (obj->mm.quirked) {
		err = -EFAULT;
		goto err_unlock;
	}

	if (obj->mm.mapping) {
		err = -EBUSY;
		goto err_unlock;
	}

	pages = __i915_gem_object_unset_pages(obj);

	obj->ops = &i915_gem_phys_ops;

	err = ____i915_gem_object_get_pages(obj);
	if (err)
		goto err_xfer;

	/* Perma-pin (until release) the physical set of pages */
	__i915_gem_object_pin_pages(obj);

	if (!IS_ERR_OR_NULL(pages)) {
		i915_gem_shmem_ops.put_pages(obj, pages);
		i915_gem_object_release_memory_region(obj);
	}
	mutex_unlock(&obj->mm.lock);
	return 0;

err_xfer:
	obj->ops = &i915_gem_shmem_ops;
	if (!IS_ERR_OR_NULL(pages)) {
		unsigned int sg_page_sizes = i915_sg_page_sizes(pages->sgl);

		__i915_gem_object_set_pages(obj, pages, sg_page_sizes);
	}
err_unlock:
	mutex_unlock(&obj->mm.lock);
	return err;
}

#if IS_ENABLED(CONFIG_DRM_I915_SELFTEST)
#include "selftests/i915_gem_phys.c"
#endif
