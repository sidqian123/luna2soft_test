/*	$NetBSD: msg_045.c,v 1.6 2022/06/20 21:13:36 rillig Exp $	*/
# 3 "msg_045.c"

/* Test for message: base type is really '%s %s' [45] */

/* lint1-flags: -tw */

struct counter {
	int value;
};

function()
{
	/* expect+4: warning: base type is really 'struct counter' [45] */
	/* expect+3: warning: declaration of 'union counter' introduces new type in ANSI C [44] */
	/* expect+2: error: 'counter' has incomplete type 'incomplete union counter' [31] */
	/* expect+1: warning: union 'counter' never defined [234] */
	union counter counter;
	/* expect+1: warning: illegal use of member 'value' [102] */
	counter.value++;
}
