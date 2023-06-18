/*	$NetBSD: dma-buf.h,v 1.12 2021/12/19 12:01:40 riastradh Exp $	*/

/*-
 * Copyright (c) 2018 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Taylor R. Campbell.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LINUX_DMA_BUF_H_
#define _LINUX_DMA_BUF_H_

#include <sys/types.h>
#include <sys/bus.h>
#include <sys/mutex.h>

#include <linux/err.h>
#include <linux/dma-mapping.h>
#include <linux/dma-resv.h>
#include <linux/scatterlist.h>

struct device;
struct dma_buf;
struct dma_buf_attachment;
struct dma_buf_export_info;
struct dma_buf_ops;
struct file;
struct module;
struct dma_resv;
struct sg_table;
struct uvm_object;

struct dma_buf_ops {
	bool	cache_sgt_mapping;
	bool	dynamic_mapping;
	int	(*attach)(struct dma_buf *, struct dma_buf_attachment *);
	void	(*detach)(struct dma_buf *, struct dma_buf_attachment *);
	struct sg_table *
		(*map_dma_buf)(struct dma_buf_attachment *,
		    enum dma_data_direction);
	void	(*unmap_dma_buf)(struct dma_buf_attachment *,
		    struct sg_table *, enum dma_data_direction);
	void	(*release)(struct dma_buf *);
	int	(*begin_cpu_access)(struct dma_buf *, enum dma_data_direction);
	int	(*end_cpu_access)(struct dma_buf *, enum dma_data_direction);
	int	(*mmap)(struct dma_buf *, off_t *, size_t, int, int *,
		    int *, struct uvm_object **, int *);
	void *	(*vmap)(struct dma_buf *);
	void	(*vunmap)(struct dma_buf *, void *);
};

struct dma_buf {
	void				*priv;
	const struct dma_buf_ops	*ops;
	size_t				size;
	struct dma_resv			*resv;

	kmutex_t			db_lock;
	volatile unsigned		db_refcnt;
	struct dma_resv_poll		db_resv_poll;
	struct dma_resv			db_resv_int[];
};

struct dma_buf_attachment {
	void				*priv;
	struct dma_buf			*dmabuf;
	bus_dma_tag_t			dev; /* XXX expedient misnomer */
	bool				dynamic_mapping;
};

struct dma_buf_export_info {
#if 0
	const char			*exp_name;
	struct module			*owner;
#endif
	const struct dma_buf_ops	*ops;
	size_t				size;
	int				flags;
	struct dma_resv			*resv;
	void				*priv;
};

#define	DEFINE_DMA_BUF_EXPORT_INFO(info)				      \
	struct dma_buf_export_info info = { .priv = NULL }

#define	dma_buf_attach		linux_dma_buf_attach
#define	dma_buf_detach		linux_dma_buf_detach
#define	dma_buf_dynamic_attach	linux_dma_buf_dynamic_attach
#define	dma_buf_export		linux_dma_buf_export
#define	dma_buf_fd		linux_dma_buf_fd
#define	dma_buf_get		linux_dma_buf_get
#define	dma_buf_map_attachment	linux_dma_buf_map_attachment
#define	dma_buf_put		linux_dma_buf_put
#define	dma_buf_unmap_attachment linux_dma_buf_unmap_attachment
#define	get_dma_buf		linux_get_dma_buf

struct dma_buf *
	dma_buf_export(struct dma_buf_export_info *);

int	dma_buf_fd(struct dma_buf *, int);
struct dma_buf *
	dma_buf_get(int);
void	get_dma_buf(struct dma_buf *);
void	dma_buf_put(struct dma_buf *);

struct dma_buf_attachment *
	dma_buf_attach(struct dma_buf *, bus_dma_tag_t);
struct dma_buf_attachment *
	dma_buf_dynamic_attach(struct dma_buf *, bus_dma_tag_t, bool);
void	dma_buf_detach(struct dma_buf *, struct dma_buf_attachment *);

struct sg_table *
	dma_buf_map_attachment(struct dma_buf_attachment *,
	    enum dma_data_direction);
void	dma_buf_unmap_attachment(struct dma_buf_attachment *,
	    struct sg_table *, enum dma_data_direction);

#endif  /* _LINUX_DMA_BUF_H_ */
