/*	$NetBSD: msg_299.c,v 1.4 2022/10/01 09:42:40 rillig Exp $	*/
# 3 "msg_299.c"

/* Test for message: prototype does not match old-style definition, arg #%d [299] */

/* lint1-flags: -w */

old_style(x)
	double x;
{
	return x > 0.0;
}

/* expect+1: error: prototype does not match old-style definition, arg #1 [299] */
void old_style(char ch);
