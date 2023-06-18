/*	$NetBSD: msg_032.c,v 1.6 2022/10/01 09:42:40 rillig Exp $	*/
# 3 "msg_032.c"

// Test for message: type of argument '%s' defaults to 'int' [32]

/* expect+5: error: old-style declaration; add 'int' [1] */
add(a, b, c)
/* expect+3: warning: type of argument 'a' defaults to 'int' [32] */
/* expect+2: warning: type of argument 'b' defaults to 'int' [32] */
/* expect+1: warning: type of argument 'c' defaults to 'int' [32] */
{
	return a + b + c;
}
