/*	$NetBSD: msg_047.c,v 1.5 2022/06/20 21:13:36 rillig Exp $	*/
# 3 "msg_047.c"

/* Test for message: zero sized %s is a C99 feature [47] */

/* lint1-flags: -sw */

struct empty {
	/* TODO: The C99 syntax in 6.7.2.1 requires at least 1 member. */
};
/* expect-1: error: zero sized struct is a C99 feature [47] */

struct zero_sized {
	/* expect+2: error: zero sized array is a C99 extension [322] */
	/* expect+1: error: zero-sized array 'dummy' in struct is a C99 extension [39] */
	char dummy[0];
};
/* expect-1: error: zero sized struct is a C99 feature [47] */
