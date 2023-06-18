/* $NetBSD: fuse_internal.h,v 1.5 2022/01/22 08:09:39 pho Exp $ */

/*
 * Copyright (c) 2021 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#if !defined(FUSE_INTERNAL_H)
#define FUSE_INTERNAL_H

/* We emit a compiler warning for anyone including <fuse.h> without
 * defining FUSE_USE_VERSION. Exempt ourselves here, or we'll be
 * warned too. */
#define _REFUSE_IMPLEMENTATION_

#include <fuse.h>
#include <fuse_lowlevel.h>
#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* This is the private fuse structure. We can freely change its size
 * and/or layout without worrying about ABI breakage. */
struct fuse {
	struct puffs_usermount	*pu;
	int			dead;
	struct fuse_fs		*fs; /* The base filesystem layer. */
};

enum refuse_show_help_variant {
	REFUSE_SHOW_HELP_FULL		= 1,
	REFUSE_SHOW_HELP_NO_HEADER	= 2,
};

/* Internal functions, hidden from users */
__BEGIN_HIDDEN_DECLS
int __fuse_set_signal_handlers(struct fuse* fuse);
int __fuse_remove_signal_handlers(struct fuse* fuse);
struct fuse* __fuse_setup(int argc, char* argv[],
                          const void* op, int op_version, void* user_data,
                          struct fuse_cmdline_opts* opts);
void __fuse_teardown(struct fuse* fuse);

/* Generic implementation of fuse_new(). The exact type of "op" is
 * determined by op_version. */
struct fuse* __fuse_new(struct fuse_args *args, const void* op,
                        int op_version, void* user_data);

int __fuse_mount(struct fuse *fuse, const char *mountpoint);
void __fuse_unmount(struct fuse *fuse);
void __fuse_destroy(struct fuse *fuse);
int __fuse_loop_mt(struct fuse *fuse, struct fuse_loop_config *config);
int __fuse_parse_cmdline(struct fuse_args *args, struct fuse_cmdline_opts *opts);
__END_HIDDEN_DECLS

#ifdef __cplusplus
}
#endif

#endif
