#	$NetBSD: Makefile,v 1.5 2013/11/17 04:45:35 nisimura Exp $

# Makefile for soft68k tags file

# Find where m68k source files are for inclusion in tags
.include <../m68k/Makefile.inc>

Tsoft68K=	../soft68k/tags
Ssoft68K=	../soft68k/soft68k/*.[ch] ../soft68k/include/*.h \
		../soft68k/dev/*.[ch]
Asoft68K=	../soft68k/soft68k/*.s

# Directories in which to place tags links
Dsoft68K=	dev include

.include "../../kern/Make.tags.inc"

tags:soft
	-ctags -wdtf ${Tsoft68K} ${Ssoft68K} ${COMM}
	egrep "^ENTRY(.*)|^ALTENTRY(.*)" ${Asoft68K} | \
	    ${TOOL_SED} -e \
		"s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 \1 /^\2(\3\4$$/;" \
	    >> ${Tsoft68K}
	sort -o ${Tsoft68K} ${Tsoft68K}

links:
	-for i in ${Dsoft68K}; do \
	    cd $$i && rm -f tags; ln -s ../tags tags; done

SUBDIR=	compile include stand

.include <bsd.subdir.mk>
