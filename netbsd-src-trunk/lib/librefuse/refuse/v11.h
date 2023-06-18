/* $NetBSD: v11.h,v 1.1 2022/01/22 08:09:40 pho Exp $ */

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
#if !defined(_FUSE_V11_H_)
#define _FUSE_V11_H_

/* Compatibility header with FUSE 1.1 API. Only declarations that have
 * differences between versions should be listed here. */

#if !defined(FUSE_H_)
#  error Do not include this header directly. Include <fuse.h> instead.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Function to add an entry in a getdir() operation in FUSE < 2.2. It
 * didn't take ino_t at that time. */
typedef int (*fuse_dirfil_t_v11)(fuse_dirh_t handle, const char *name, int type);

/* The table of file system operations in FUSE < 2.1. */
struct fuse_operations_v11 {
	int	(*getattr)	(const char *, struct stat *);
	int	(*readlink)	(const char *, char *, size_t);
	int	(*getdir)	(const char *, fuse_dirh_t, fuse_dirfil_t_v11);
	int	(*mknod)	(const char *, mode_t, dev_t);
	int	(*mkdir)	(const char *, mode_t);
	int	(*unlink)	(const char *);
	int	(*rmdir)	(const char *);
	int	(*symlink)	(const char *, const char *);
	int	(*rename)	(const char *, const char *);
	int	(*link)		(const char *, const char *);
	int	(*chmod)	(const char *, mode_t);
	int	(*chown)	(const char *, uid_t, gid_t);
	int	(*truncate)	(const char *, off_t);
	int	(*utime)	(const char *, struct utimbuf *);
	int	(*open)		(const char *, int);
	int	(*read)		(const char *, char *, size_t, off_t);
	int	(*write)	(const char *, const char *, size_t, off_t);
	int	(*statfs)	(const char *, struct fuse_statfs *);
	int	(*release)	(const char *, int);
	int	(*fsync)	(const char *, int);
};

/* Mount a FUSE < 2.1 filesystem. */
int fuse_mount_v11(const char *mountpoint, const char *argv[]);

/* Unmount a FUSE < 2.6 filesystem. */
void fuse_unmount_v11(const char *mountpoint);

/* Create a FUSE < 2.1 filesystem. */
struct fuse *fuse_new_v11(int fd, int flags, const void *op, int op_version);

/* Destroy a FUSE < 3.0 filesystem. */
void fuse_destroy_v11(struct fuse *);

/* Multithreaded event loop for FUSE < 3.0 */
int fuse_loop_mt_v11(struct fuse *);

#ifdef __cplusplus
}
#endif

#endif
