/*	$NetBSD: drm_writeback.h,v 1.6 2021/12/19 10:46:03 riastradh Exp $	*/

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

#ifndef	_DRM_DRM_WRITEBACK_H_
#define	_DRM_DRM_WRITEBACK_H_

#include <drm/drm_connector.h>

struct dma_fence;
struct drm_connector;
struct drm_connector_state;
struct drm_framebuffer;
struct drm_writeback_connector;

struct drm_writeback_connector {
	struct drm_connector	base;
};

struct drm_writeback_job {
	struct drm_framebuffer	*fb;
	struct dma_fence	*out_fence;
};

struct drm_writeback_connector *
	drm_connector_to_writeback(struct drm_connector *);
struct dma_fence *
	drm_writeback_get_out_fence(struct drm_writeback_connector *);
int	drm_writeback_prepare_job(struct drm_writeback_job *);
void	drm_writeback_cleanup_job(struct drm_writeback_job *);
int	drm_writeback_set_fb(struct drm_connector_state *,
	    struct drm_framebuffer *);

#endif	/* _DRM_DRM_WRITEBACK_H_ */
