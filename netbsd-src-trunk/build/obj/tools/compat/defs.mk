#	$NetBSD: defs.mk.in,v 1.12 2012/12/02 13:05:14 apb Exp $
#
# Makefile fragment for building with libnbcompat and associated
# include files.  It can also be used for building just with
# the include files, without the library.
#
# This can be used when the library and include files have been installed
# into TOOLDIR (by "make install" in the src/tools/compat directory),
# or when they have not been installed into TOOLDIR but reside
# in the .OBJDIR associated with src/tools/compat.
#
# Variables:
#
# COMPATLIB_UNINSTALLED:
#		If "yes", then use the files from the .OBJDIR of
#		NETBSDSRCDIR/tools/compat.  Otherwise, use the files
#		from TOOLDIR.
#
# COMPATLIB_NO_LIB:
#		If "yes" then do not use the library (but still use
#		the include files).
#
# Examples:
#
# * Use uninstalled copy of libnbcompat and associated *.h files:
#
#	COMPATLIB_UNINSTALLED= yes
#	COMPATOBJ!=	cd ${NETBSDSRCDIR}/tools/compat && ${PRINTOBJDIR}
#	.-include	"${COMPATOBJ}/defs.mk"
#
# * Use TOOLDIR copy of libnbcompat and associated *.h files:
#
#	.-include	"${TOOLDIR}/share/compat/defs.mk"
#
# * Use TOOLDIR copy of compat *.h files, but do not use libnbcompat.a:
#
#	COMPATLIB_NO_LIB= yes
#	.-include	"${TOOLDIR}/share/compat/defs.mk"
#
# The use of ".-include" instead of ".include" above is because it's
# expected that the file might not exist during "make obj" or "make clean".
#

.include <bsd.own.mk>

# Use the installed (TOOLDIR) version of the library and headers by default
COMPATLIB_UNINSTALLED ?= no
# Use library and includes by default.
COMPATLIB_NO_LIB ?= no

.if "${COMPATLIB_UNINSTALLED}" == "yes"
# The library lives in the .OBJDIR.
#
# Some include files live directly in the .OBJDIR, while others
# live in subdirectories of .OBJDIR/include.
#
COMPATOBJ:=	${.PARSEDIR}
COMPATLIBDIR=	${COMPATOBJ}
COMPATINCFLAGS=	-I${COMPATOBJ} -I${COMPATOBJ}/include
.else
# The library lives in TOOLDIR/lib.
#
# All include files live in TOOLDIR/include/comnpat, and its subdirectories.
#
COMPATLIBDIR=	${TOOLDIR}/lib
COMPATINCFLAGS=	-I${TOOLDIR}/include/compat
.endif

HOSTEXEEXT=	
HOST_BSHELL=	/bin/sh

BUILD_OSTYPE!=  uname -s

# Disable use of pre-compiled headers on Darwin.
.if ${BUILD_OSTYPE} == "Darwin"
HOST_CPPFLAGS+=	-no-cpp-precomp
.endif

HOST_CPPFLAGS+=	${COMPATINCFLAGS} -I${NETBSDSRCDIR}/tools/compat \
		-DHAVE_NBTOOL_CONFIG_H=1 -D_FILE_OFFSET_BITS=64

.if "${COMPATLIB_NO_LIB}" != "yes"
DPADD+=		${COMPATLIBDIR}/libnbcompat.a
LDADD+=		-L${COMPATLIBDIR} -lnbcompat -lz 
.endif # ! COMPATLIB_NO_LIB

HAVE_PTHREAD_H=	yes
