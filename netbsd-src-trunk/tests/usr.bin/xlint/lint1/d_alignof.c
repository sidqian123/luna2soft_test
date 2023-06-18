/*	$NetBSD: d_alignof.c,v 1.8 2022/06/22 19:23:18 rillig Exp $	*/
# 3 "d_alignof.c"

/* https://gcc.gnu.org/onlinedocs/gcc/Alignment.html */

unsigned long
leading_and_trailing_alignof_type(void)
{
	return __alignof__(short);
}

unsigned long
leading_alignof_type(void)
{
	return __alignof(short);
}

unsigned long
plain_alignof_type(void)
{
	/* The plain word 'alignof' is not recognized by GCC. */
	/* expect+2: error: function 'alignof' implicitly declared to return int [215] */
	/* expect+1: error: syntax error 'short' [249] */
	return alignof(short);
}
/* expect-1: warning: function 'plain_alignof_type' falls off bottom without returning value [217] */

unsigned long
leading_and_trailing_alignof_expr(void)
{
	return __alignof__ 3;
}

unsigned long
leading_alignof_expr(void)
{
	return __alignof 3;
}

unsigned long
plain_alignof_expr(void)
{
	/* The plain word 'alignof' is not recognized by GCC. */
	/* expect+2: error: 'alignof' undefined [99] */
	/* expect+1: error: syntax error '3' [249] */
	return alignof 3;
}
/* expect-1: warning: function 'plain_alignof_expr' falls off bottom without returning value [217] */


/*
 * As with 'sizeof', the keyword '__alignof__' doesn't require parentheses
 * when followed by an expression.  This allows for the seemingly strange
 * '->' after the parentheses, which in fact is perfectly fine.
 *
 * The NetBSD style guide says "We parenthesize sizeof expressions", even
 * though it is misleading in edge cases like this.  The GCC manual says that
 * '__alignof__' and 'sizeof' are syntactically the same, therefore the same
 * reasoning applies to '__alignof__'.
 */
unsigned long
alignof_pointer_to_member(void)
{
	struct s {
		unsigned long member;
	} var = { 0 }, *ptr = &var;

	return __alignof__(ptr)->member + ptr->member;
}
