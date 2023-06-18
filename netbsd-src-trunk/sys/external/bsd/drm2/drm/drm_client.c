/*	$NetBSD: drm_client.c,v 1.3 2021/12/19 11:07:55 riastradh Exp $	*/

/*-
 * Copyright (c) 2020 The NetBSD Foundation, Inc.
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

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: drm_client.c,v 1.3 2021/12/19 11:07:55 riastradh Exp $");

#include <sys/kmem.h>

#include <linux/err.h>

#include <drm/drm_client.h>
#include <drm/drm_drv.h>

int
drm_client_init(struct drm_device *dev, struct drm_client_dev *client,
    const char *name, const struct drm_client_funcs *funcs)
{
	int ret;

	client->dev = dev;

	ret = drm_client_modeset_create(client);
	if (ret)
		goto out0;

	drm_dev_get(dev);
	return 0;

out0:	return ret;
}

void
drm_client_register(struct drm_client_dev *client)
{
}

void
drm_client_release(struct drm_client_dev *client)
{

	drm_client_modeset_free(client);
	drm_dev_put(client->dev);
}

void
drm_client_dev_hotplug(struct drm_device *dev)
{
}

void
drm_client_dev_restore(struct drm_device *dev)
{
}

void
drm_client_dev_unregister(struct drm_device *dev)
{
}

struct drm_client_buffer *
drm_client_framebuffer_create(struct drm_client_dev *client,
    u32 width, u32 height, u32 format)
{
	struct drm_client_buffer *buffer;

	buffer = kmem_zalloc(sizeof(*buffer), KM_SLEEP);

	return buffer;
}

void *
drm_client_buffer_vmap(struct drm_client_buffer *buffer)
{
	return ERR_PTR(-ENODEV);
}

void
drm_client_buffer_vunmap(struct drm_client_buffer *buffer)
{
	panic("impossible");
}

void
drm_client_framebuffer_delete(struct drm_client_buffer *buffer)
{
	kmem_free(buffer, sizeof(*buffer));
}
