/*	$NetBSD: fmt_decl.c,v 1.43 2023/05/16 08:22:11 rillig Exp $	*/

/*
 * Tests for declarations of global variables, external functions, and local
 * variables.
 *
 * See also:
 *	opt_di.c
 */

/* See FreeBSD r303570 */

/*
 * A type definition usually declares a single type, so there is no need to
 * align the newly declared type name with the other variables.
 */
//indent input
typedef   void   (   *   function_ptr   )   (   int   *   )   ;
//indent end

//indent run
typedef void (*function_ptr)(int *);
//indent end


/*
 * In variable declarations, the names of the first declarators are indented
 * by the amount given in '-di', which defaults to 16.
 */
//indent input
extern   void   (   *   function_pointer   )   (   int   *   )   ;
extern   void   *   pointer;
//indent end

//indent run
/* $ XXX: Why is the token 'function_pointer' not aligned with 'pointer'? */
extern void	(*function_pointer)(int *);
extern void    *pointer;
//indent end


//indent input
static const struct
{
	double		x;
	double		y, z;
} n[m + 1] =
{
	{
		.0,
		.9,
		5
	}
};
//indent end

//indent run
static const struct
{
	double		x;
	double		y, z;
}		n[m + 1] =
{
	{
		.0,
		.9,
		5
	}
};
//indent end


//indent input
typedef struct Complex
{
	double		x;
	double		y;
}	Complex;
//indent end

//indent run
typedef struct Complex
{
	double		x;
	double		y;
}		Complex;
//indent end


/*
 * Ensure that function definitions are reasonably indented.  Before
 * 2023-05-11, tokens were repeatedly read, and the line numbers were wrong.
 */
//indent input
void
t1 (char *a, int b,
	void (*fn)(void))
{}
//indent end

//indent run
void
t1(char *a, int b,
   void (*fn)(void))
{
}
//indent end


/* See opt_bc.c. */
//indent input
void t2 (char *x, int y)
{
	int a,
	b,
	c;
	int
	*d,
	*e,
	*f;
	int (*g)(),
	(*h)(),
	(*i)();
	int j,
	k,
	l;
	int m
	,n
	,o
	;
	int		chars[ /* push the comma beyond column 74 ...... */ ], x;
}
//indent end

//indent run
void
t2(char *x, int y)
{
	int		a, b, c;
	int
		       *d, *e, *f;
	int		(*g)(), (*h)(), (*i)();
	int		j, k, l;
	int		m
		       ,n
		       ,o
		       ;
	int		chars[/* push the comma beyond column 74 ...... */],
			x;
}
//indent end


//indent input
const int	int_minimum_size =
MAXALIGN(offsetof(int, test)) + MAXIMUM_ALIGNOF;
//indent end

//indent run-equals-input


/*
 * Ensure that the usual GCC-style function attributes are formatted in a
 * sensible way.
 */
//indent input
void single_param(int) __attribute__((__noreturn__)) ;
void function(const char *, ...) __attribute__((format(printf, 1, 2))) ;
//indent end

//indent run -di0
void single_param(int) __attribute__((__noreturn__));
void function(const char *, ...) __attribute__((format(printf, 1, 2)));
//indent end

//indent run
void		single_param(int) __attribute__((__noreturn__));
void		function(const char *, ...) __attribute__((format(printf, 1, 2)));
//indent end


//indent input
static
_attribute_printf(1, 2)
void
print_error(const char *fmt,...)
{
}
//indent end

//indent run
static
_attribute_printf(1, 2)
void
print_error(const char *fmt, ...)
{
}
//indent end


//indent input
static _attribute_printf(1, 2)
void
print_error(const char *fmt,...)
{
}
//indent end

//indent run
static _attribute_printf(1, 2)
void
print_error(const char *fmt, ...)
{
}
//indent end


//indent input
static void _attribute_printf(1, 2)
print_error(const char *fmt,...)
{
}
//indent end

//indent run
static void
_attribute_printf(1, 2)
print_error(const char *fmt, ...)
{
}
//indent end


/* See FreeBSD r309380 */
//indent input
static LIST_HEAD(, alq) ald_active;
static int ald_shutting_down = 0;
struct thread *ald_thread;
//indent end

//indent run
static LIST_HEAD(, alq) ald_active;
static int	ald_shutting_down = 0;
struct thread  *ald_thread;
//indent end


//indent input
static int
old_style_definition(a, b, c)
	struct thread *a;
	int b;
	double ***c;
{

}
//indent end

//indent run
static int
old_style_definition(a, b, c)
	struct thread  *a;
	int		b;
	double	     ***c;
{

}
//indent end


/*
 * Demonstrate how variable declarations are broken into several lines when
 * the line length limit is set quite low.
 */
//indent input
struct s a,b;
struct s0 a,b;
struct s01 a,b;
struct s012 a,b;
struct s0123 a,b;
struct s01234 a,b;
struct s012345 a,b;
struct s0123456 a,b;
struct s01234567 a,b;
struct s012345678 a,b;
struct s0123456789 a,b;
struct s01234567890 a,b;
struct s012345678901 a,b;
struct s0123456789012 a,b;
struct s01234567890123 a,b;
//indent end

//indent run -l20 -di0
struct s a, b;
/* $ XXX: See process_comma, varname_len for why this line is broken. */
struct s0 a,
   b;
/* $ XXX: The indentation of the second line is wrong. The variable names */
/* $ XXX: 'a' and 'b' should be in the same column; the word 'struct' is */
/* $ XXX: missing in the calculation for the indentation. */
struct s01 a,
    b;
struct s012 a,
     b;
struct s0123 a,
      b;
struct s01234 a,
       b;
struct s012345 a,
        b;
struct s0123456 a,
         b;
struct s01234567 a,
          b;
struct s012345678 a,
           b;
struct s0123456789 a,
            b;
struct s01234567890 a,
             b;
struct s012345678901 a,
              b;
struct s0123456789012 a,
               b;
struct s01234567890123 a,
                b;
//indent end


//indent input
char * x(void)
{
    type identifier;
    type *pointer;
    unused * value;
    (void)unused * value;

    dmax = (double)3 * 10.0;
    dmin = (double)dmax * 10.0;
    davg = (double)dmax * dmin;

    return NULL;
}
//indent end

//indent run
char *
x(void)
{
	type		identifier;
	type	       *pointer;
	unused	       *value;
	(void)unused * value;

	dmax = (double)3 * 10.0;
	dmin = (double)dmax * 10.0;
	davg = (double)dmax * dmin;

	return NULL;
}
//indent end


//indent input
int *
y(void) {

}

int
z(void) {

}
//indent end

//indent run
int *
y(void)
{

}

int
z(void)
{

}
//indent end


//indent input
int x;
int *y;
int * * * * z;
//indent end

//indent run
int		x;
int	       *y;
int	    ****z;
//indent end


//indent input
int main(void) {
    char (*f1)() = NULL;
    char *(*f1)() = NULL;
    char *(*f2)();
}
//indent end

/*
 * Before NetBSD io.c 1.103 from 2021-10-27, indent wrongly placed the second
 * and third variable declaration in column 1. This bug has been introduced
 * to NetBSD when FreeBSD indent was imported in 2019.
 */
//indent run -ldi0
int
main(void)
{
	char (*f1)() = NULL;
	char *(*f1)() = NULL;
	char *(*f2)();
}
//indent end

//indent run
int
main(void)
{
/* $ XXX: Not really pretty, the name 'f1' should be aligned, if at all. */
	char		(*f1)() = NULL;
/* $ XXX: Not really pretty, the name 'f1' should be aligned, if at all. */
	char *(*	f1)() = NULL;
/* $ XXX: Not really pretty, the name 'f2' should be aligned, if at all. */
	char *(*	f2)();
}
//indent end


/*
 * In some ancient time long before ISO C90, variable declarations with
 * initializer could be written without '='. The C Programming Language from
 * 1978 doesn't mention this form anymore.
 *
 * Before NetBSD lexi.c 1.123 from 2021-10-31, indent treated the '-' as a
 * unary operator.
 */
//indent input
int a - 1;
{
int a - 1;
}
//indent end

//indent run -di0
int a - 1;
{
	int a - 1;
}
//indent end


/*
 * Between 2019-04-04 and before lexi.c 1.146 from 2021-11-19, the indentation
 * of the '*' depended on the function name, which did not make sense.  For
 * function names that matched [A-Za-z]+, the '*' was placed correctly, for
 * all other function names (containing [$0-9_]) the '*' was right-aligned on
 * the declaration indentation, which defaults to 16.
 */
//indent input
int *
f2(void)
{
}

int *
yy(void)
{
}

int *
int_create(void)
{
}
//indent end

//indent run-equals-input


/*
 * Since 2019-04-04, the space between the '){' is missing.
 */
//indent input
int *
function_name_____20________30________40________50
(void)
{}
//indent end

/*
 * Before 2023-05-11, indent moved the '{' right after the '(void)', without
 * any space in between.
 */
//indent run
int	       *function_name_____20________30________40________50
		(void)
{
}
//indent end


/*
 * Since 2019-04-04 and before lexi.c 1.144 from 2021-11-19, some function
 * names were preserved while others were silently discarded.
 */
//indent input
int *
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
(void)
{}
//indent end

/*
 * Before 2023-05-11, indent moved the '{' right after the '(void)', without
 * any space in between.
 */
//indent run
int	       *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		(void)
{
}
//indent end


/*
 * Before 1990, when C90 standardized function prototypes, a function
 * declaration or definition did not contain a '*' that may have looked
 * similar to the binary operator '*' because it was surrounded by two
 * identifiers.
 *
 * As of 2021-11-21, indent interpreted the '*' in the function declaration in
 * line 1 as a binary operator, even though the '*' was followed by a ','
 * directly. This was not visible in the output though since indent never
 * outputs a space before a comma.
 *
 * In the function declaration in line 2 and the function definition in line
 * 5, indent interpreted the '*' as a binary operator as well and accordingly
 * placed spaces around the '*'. On a very low syntactical analysis level,
 * this may have made sense since the '*' was surrounded by words, but still
 * the '*' is part of a declaration, where a binary operator does not make
 * sense.
 *
 * Essentially, as of 2021, indent had missed the last 31 years of advances in
 * the C programming language, in particular the invention of function
 * prototypes. Instead, the workaround had been to require all type names to
 * be specified via the options '-ta' and '-T'. This put the burden on the
 * user instead of the implementer.
 *
 * Fixed in lexi.c 1.156 from 2021-11-25.
 */
//indent input
void		buffer_add(buffer *, char);
void		buffer_add(buffer *buf, char ch);

void
buffer_add(buffer *buf, char ch)
{
	*buf->e++ = ch;
}
//indent end

/* Before lexi.c 1.156 from 2021-11-25, indent generated 'buffer * buf'. */
//indent run
void		buffer_add(buffer *, char);
/* $ FIXME: space after '*' */
void		buffer_add(buffer * buf, char ch);

void
buffer_add(buffer *buf, char ch)
{
	*buf->e++ = ch;
}
//indent end


/*
 * Before lexi.c 1.153 from 2021-11-25, indent did not recognize 'Token' as a
 * type name and then messed up the positioning of the '{'.
 */
//indent input
static Token
ToToken(bool cond)
{
}
//indent end

//indent run-equals-input -TToken

/* Since lexi.c 1.153 from 2021-11-25. */
//indent run-equals-input


/*
 * Indent gets easily confused by unknown type names in struct declarations.
 */
//indent input
typedef struct OpenDirs {
	CachedDirList	list;
	HashTable /* of CachedDirListNode */ table;
}		OpenDirs;
//indent end

/* FIXME: The word 'HashTable' must not be aligned like a member name. */
//indent run
typedef struct OpenDirs {
	CachedDirList	list;
			HashTable /* of CachedDirListNode */ table;
}		OpenDirs;
//indent end

//indent run-equals-input -THashTable


/*
 * Indent gets easily confused by unknown type names, even in declarations
 * that are syntactically unambiguous.
 */
//indent input
static CachedDir *dot = NULL;
//indent end

//indent run-equals-input -TCachedDir

/* Since lexi.c 1.153 from 2021-11-25. */
//indent run-equals-input


/*
 * Before lexi.c 1.156 from 2021-11-25, indent easily got confused by unknown
 * type names in declarations and generated 'HashEntry * he' with an extra
 * space.
 */
//indent input
static CachedDir *
CachedDir_New(const char *name)
{
}
//indent end

/* Since lexi.c 1.153 from 2021-11-25. */
//indent run-equals-input


/*
 * Before lexi.c 1.156 from 2021-11-25, indent easily got confused by unknown
 * type names in declarations and generated 'CachedDir * dir' with an extra
 * space.
 */
//indent input
static CachedDir *
CachedDir_Ref(CachedDir *dir)
{
}
//indent end

//indent run-equals-input


/*
 * Before lexi.c 1.156 from 2021-11-25, indent easily got confused by unknown
 * type names in declarations and generated 'HashEntry * he' with an extra
 * space.
 *
 * Before lexi.c 1.153 from 2021-11-25, indent also placed the '{' at the end
 * of the line.
 */
//indent input
static bool
HashEntry_KeyEquals(const HashEntry *he, Substring key)
{
}
//indent end

//indent run-equals-input


/*
 * Before lexi.c 1.156 from 2021-11-25, indent didn't notice that the two '*'
 * are in a declaration, instead it interpreted the first '*' as a binary
 * operator, therefore generating 'CachedDir * *var' with an extra space.
 */
//indent input
static void
CachedDir_Assign(CachedDir **var, CachedDir *dir)
{
}
//indent end

//indent run-equals-input

//indent run-equals-input -TCachedDir


/*
 * Before lexi.c 1.153 from 2021-11-25, all initializer expressions after the
 * first one were indented as if they would be statement continuations. This
 * was because the token 'Shell' was identified as a word, not as a type name.
 */
//indent input
static Shell	shells[] = {
	{
		first,
		second,
	},
};
//indent end

/* Since lexi.c 1.153 from 2021-11-25. */
//indent run-equals-input


/*
 * Before lexi.c 1.158 from 2021-11-25, indent easily got confused by function
 * attribute macros that followed the function declaration. Its primitive
 * heuristic between deciding between a function declaration and a function
 * definition only looked for ')' immediately followed by ',' or ';'. This was
 * sufficient for well-formatted code before 1990. With the addition of
 * function prototypes and GCC attributes, the situation became more
 * complicated, and it took indent 31 years to adapt to this new reality.
 */
//indent input
static void JobInterrupt(bool, int) MAKE_ATTR_DEAD;
static void JobRestartJobs(void);
//indent end

//indent run
static void	JobInterrupt(bool, int) MAKE_ATTR_DEAD;
static void	JobRestartJobs(void);
//indent end


/*
 * Before lexi.c 1.158 from 2021-11-25, indent easily got confused by the
 * tokens ')' and ';' in the function body. It wrongly regarded them as
 * finishing a function declaration.
 */
//indent input
MAKE_INLINE const char *
GNode_VarTarget(GNode *gn) { return GNode_ValueDirect(gn, TARGET); }
//indent end

/*
 * Before lexi.c 1.156 from 2021-11-25, indent generated 'GNode * gn' with an
 * extra space.
 *
 * Before lexi.c 1.158 from 2021-11-25, indent wrongly placed the function
 * name in line 1, together with the '{'.
 */
//indent run
MAKE_INLINE const char *
GNode_VarTarget(GNode *gn)
{
	return GNode_ValueDirect(gn, TARGET);
}
//indent end

//indent run-equals-prev-output -TGNode


/*
 * Ensure that '*' in declarations is interpreted (or at least formatted) as
 * a 'pointer to' type derivation, not as a binary or unary operator.
 */
//indent input
number *var = a * b;

void
function(void)
{
	number *var = a * b;
}
//indent end

//indent run-equals-input -di0


/*
 * In declarations, most occurrences of '*' are pointer type derivations.
 * There are a few exceptions though. Some of these are hard to detect
 * without knowing which identifiers are type names.
 */
//indent input
char str[expr * expr];
char str[expr**ptr];
char str[*ptr**ptr];
char str[sizeof(expr * expr)];
char str[sizeof(int) * expr];
char str[sizeof(*ptr)];
char str[sizeof(type**)];
char str[sizeof(**ptr)];
//indent end

//indent run -di0
char str[expr * expr];
char str[expr * *ptr];
char str[*ptr * *ptr];
char str[sizeof(expr * expr)];
char str[sizeof(int) * expr];
char str[sizeof(*ptr)];
/* $ FIXME: should be 'type **' */
char str[sizeof(type * *)];
char str[sizeof(**ptr)];
//indent end


/*
 * Since lexi.c 1.158 from 2021-11-25, whether the function 'a' was considered
 * a declaration or a definition depended on the preceding struct, in
 * particular the length of the 'pn' line. This didn't make sense at all and
 * was due to an out-of-bounds memory access.
 *
 * Seen amongst others in args.c 1.72, function add_typedefs_from_file.
 * Fixed in lexi.c 1.165 from 2021-11-27.
 */
//indent input
struct {
} v = {
    pn("ta"),
};

static void
a(char *fe)
{
}

struct {
} v = {
    pn("t"),
};

static void
a(char *fe)
{
}
//indent end

//indent run -di0
struct {
} v = {
	pn("ta"),
};

static void
a(char *fe)
{
}

struct {
} v = {
	pn("t"),
};

static void
a(char *fe)
{
}
//indent end


/*
 * Before NetBSD indent.c 1.178 from 2021-10-29, indent removed the blank
 * before the '=', in the second and third of these function pointer
 * declarations. This was because indent interpreted the prototype parameters
 * 'int' and 'int, int' as type casts, which doesn't make sense at all. Fixing
 * this properly requires large style changes since indent is based on simple
 * heuristics all over. This didn't change in indent.c 1.178; instead, the
 * rule for inserting a blank before a binary operator was changed to always
 * insert a blank, except at the beginning of a line.
 */
//indent input
char *(*fn)() = NULL;
char *(*fn)(int) = NULL;
char *(*fn)(int, int) = NULL;
//indent end

/* XXX: The parameter '(int)' is wrongly interpreted as a type cast. */
/* XXX: The parameter '(int, int)' is wrongly interpreted as a type cast. */
//indent run-equals-input -di0


/*
 * Depending on whether there was a line break in the function header, the
 * spaces around the '||' operator were erroneously removed.
 */
//indent input
bool is_identifier_start(char ch)
{
	return ch_isalpha(ch) || ch == '_';
}

bool
is_identifier_start(char ch)
{
	return ch_isalpha(ch) || ch == '_';
}
//indent end

//indent run
bool
is_identifier_start(char ch)
{
	return ch_isalpha(ch) || ch == '_';
}

bool
is_identifier_start(char ch)
{
	return ch_isalpha(ch) || ch == '_';
}
//indent end


//indent input
void buf_add_chars(struct buffer *, const char *, size_t);

static inline bool
ch_isalnum(char ch)
{
    return isalnum((unsigned char)ch) != 0;
}

static inline bool
ch_isalpha(char ch)
{
    return isalpha((unsigned char)ch) != 0;
}
//indent end

//indent run -i4 -di0
// $ FIXME: 'buffer' is classified as 'word'.
// $
// $ XXX: 'char' is classified as 'type_in_parentheses'; check whether this
// $ XXX: lexer symbol should only be used for types in cast expressions.
// $
// $ FIXME: 'size_t' is classified as 'word'.
void buf_add_chars(struct buffer *, const char *, size_t);

static inline bool
ch_isalnum(char ch)
{
    return isalnum((unsigned char)ch) != 0;
}

static inline bool
ch_isalpha(char ch)
{
    return isalpha((unsigned char)ch) != 0;
}
//indent end

//indent run-equals-input -i4 -di0
