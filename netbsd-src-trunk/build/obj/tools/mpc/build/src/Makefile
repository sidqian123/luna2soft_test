# Makefile.in generated by automake 1.16.5 from Makefile.am.
# src/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2021 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



VPATH = /Users/sidqian/Downloads/netbsd-src-trunk/tools/mpc/../../external/lgpl3/mpc/dist/src
am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/mpc
pkgincludedir = $(includedir)/mpc
pkglibdir = $(libdir)/mpc
pkglibexecdir = $(libexecdir)/mpc
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-apple-darwin22.1.0
host_triplet = x86_64-apple-darwin22.1.0
subdir = src
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/ax_gcc_option.m4 \
	$(top_srcdir)/m4/ax_gcc_version.m4 $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/m4/mpc.m4 $(top_srcdir)/m4/valgrind-tests.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
am__installdirs = "$(DESTDIR)$(libdir)"
LTLIBRARIES = $(lib_LTLIBRARIES)
libmpc_la_DEPENDENCIES = 
am_libmpc_la_OBJECTS = abs.lo acos.lo acosh.lo add.lo add_fr.lo \
	add_si.lo add_ui.lo agm.lo arg.lo asin.lo asinh.lo atan.lo \
	atanh.lo clear.lo cmp.lo cmp_abs.lo cmp_si_si.lo conj.lo \
	cos.lo cosh.lo div_2si.lo div_2ui.lo div.lo div_fr.lo \
	div_ui.lo dot.lo eta.lo exp.lo fma.lo fr_div.lo fr_sub.lo \
	get_prec2.lo get_prec.lo get_version.lo get_x.lo imag.lo \
	init2.lo init3.lo inp_str.lo log.lo log10.lo mem.lo mul_2si.lo \
	mul_2ui.lo mul.lo mul_fr.lo mul_i.lo mul_si.lo mul_ui.lo \
	neg.lo norm.lo out_str.lo pow.lo pow_fr.lo pow_ld.lo pow_d.lo \
	pow_si.lo pow_ui.lo pow_z.lo proj.lo real.lo rootofunity.lo \
	urandom.lo set.lo set_prec.lo set_str.lo set_x.lo set_x_x.lo \
	sin.lo sin_cos.lo sinh.lo sqr.lo sqrt.lo strtoc.lo sub.lo \
	sub_fr.lo sub_ui.lo sum.lo swap.lo tan.lo tanh.lo \
	uceil_log2.lo ui_div.lo ui_ui_sub.lo radius.lo balls.lo
libmpc_la_OBJECTS = $(am_libmpc_la_OBJECTS)
AM_V_lt = $(am__v_lt_$(V))
am__v_lt_ = $(am__v_lt_$(AM_DEFAULT_VERBOSITY))
am__v_lt_0 = --silent
am__v_lt_1 = 
libmpc_la_LINK = $(LIBTOOL) $(AM_V_lt) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) \
	$(libmpc_la_LDFLAGS) $(LDFLAGS) -o $@
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I. -I$(srcdir) -I$(top_builddir)
depcomp = $(SHELL) $(top_srcdir)/build-aux/depcomp
am__maybe_remake_depfiles = depfiles
am__depfiles_remade = $(DEPDIR)/logging.Plo ./$(DEPDIR)/abs.Plo \
	./$(DEPDIR)/acos.Plo ./$(DEPDIR)/acosh.Plo ./$(DEPDIR)/add.Plo \
	./$(DEPDIR)/add_fr.Plo ./$(DEPDIR)/add_si.Plo \
	./$(DEPDIR)/add_ui.Plo ./$(DEPDIR)/agm.Plo ./$(DEPDIR)/arg.Plo \
	./$(DEPDIR)/asin.Plo ./$(DEPDIR)/asinh.Plo \
	./$(DEPDIR)/atan.Plo ./$(DEPDIR)/atanh.Plo \
	./$(DEPDIR)/balls.Plo ./$(DEPDIR)/clear.Plo \
	./$(DEPDIR)/cmp.Plo ./$(DEPDIR)/cmp_abs.Plo \
	./$(DEPDIR)/cmp_si_si.Plo ./$(DEPDIR)/conj.Plo \
	./$(DEPDIR)/cos.Plo ./$(DEPDIR)/cosh.Plo ./$(DEPDIR)/div.Plo \
	./$(DEPDIR)/div_2si.Plo ./$(DEPDIR)/div_2ui.Plo \
	./$(DEPDIR)/div_fr.Plo ./$(DEPDIR)/div_ui.Plo \
	./$(DEPDIR)/dot.Plo ./$(DEPDIR)/eta.Plo ./$(DEPDIR)/exp.Plo \
	./$(DEPDIR)/fma.Plo ./$(DEPDIR)/fr_div.Plo \
	./$(DEPDIR)/fr_sub.Plo ./$(DEPDIR)/get_prec.Plo \
	./$(DEPDIR)/get_prec2.Plo ./$(DEPDIR)/get_version.Plo \
	./$(DEPDIR)/get_x.Plo ./$(DEPDIR)/imag.Plo \
	./$(DEPDIR)/init2.Plo ./$(DEPDIR)/init3.Plo \
	./$(DEPDIR)/inp_str.Plo ./$(DEPDIR)/log.Plo \
	./$(DEPDIR)/log10.Plo ./$(DEPDIR)/mem.Plo ./$(DEPDIR)/mul.Plo \
	./$(DEPDIR)/mul_2si.Plo ./$(DEPDIR)/mul_2ui.Plo \
	./$(DEPDIR)/mul_fr.Plo ./$(DEPDIR)/mul_i.Plo \
	./$(DEPDIR)/mul_si.Plo ./$(DEPDIR)/mul_ui.Plo \
	./$(DEPDIR)/neg.Plo ./$(DEPDIR)/norm.Plo \
	./$(DEPDIR)/out_str.Plo ./$(DEPDIR)/pow.Plo \
	./$(DEPDIR)/pow_d.Plo ./$(DEPDIR)/pow_fr.Plo \
	./$(DEPDIR)/pow_ld.Plo ./$(DEPDIR)/pow_si.Plo \
	./$(DEPDIR)/pow_ui.Plo ./$(DEPDIR)/pow_z.Plo \
	./$(DEPDIR)/proj.Plo ./$(DEPDIR)/radius.Plo \
	./$(DEPDIR)/real.Plo ./$(DEPDIR)/rootofunity.Plo \
	./$(DEPDIR)/set.Plo ./$(DEPDIR)/set_prec.Plo \
	./$(DEPDIR)/set_str.Plo ./$(DEPDIR)/set_x.Plo \
	./$(DEPDIR)/set_x_x.Plo ./$(DEPDIR)/sin.Plo \
	./$(DEPDIR)/sin_cos.Plo ./$(DEPDIR)/sinh.Plo \
	./$(DEPDIR)/sqr.Plo ./$(DEPDIR)/sqrt.Plo \
	./$(DEPDIR)/strtoc.Plo ./$(DEPDIR)/sub.Plo \
	./$(DEPDIR)/sub_fr.Plo ./$(DEPDIR)/sub_ui.Plo \
	./$(DEPDIR)/sum.Plo ./$(DEPDIR)/swap.Plo ./$(DEPDIR)/tan.Plo \
	./$(DEPDIR)/tanh.Plo ./$(DEPDIR)/uceil_log2.Plo \
	./$(DEPDIR)/ui_div.Plo ./$(DEPDIR)/ui_ui_sub.Plo \
	./$(DEPDIR)/urandom.Plo
am__mv = mv -f
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LTCOMPILE = $(LIBTOOL) $(AM_V_lt) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) \
	$(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) \
	$(AM_CFLAGS) $(CFLAGS)
AM_V_CC = $(am__v_CC_$(V))
am__v_CC_ = $(am__v_CC_$(AM_DEFAULT_VERBOSITY))
am__v_CC_0 = @echo "  CC      " $@;
am__v_CC_1 = 
CCLD = $(CC)
LINK = $(LIBTOOL) $(AM_V_lt) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) \
	$(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CCLD = $(am__v_CCLD_$(V))
am__v_CCLD_ = $(am__v_CCLD_$(AM_DEFAULT_VERBOSITY))
am__v_CCLD_0 = @echo "  CCLD    " $@;
am__v_CCLD_1 = 
SOURCES = $(libmpc_la_SOURCES)
DIST_SOURCES = $(libmpc_la_SOURCES)
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
am__DIST_COMMON = $(srcdir)/Makefile.in \
	$(top_srcdir)/build-aux/depcomp logging.c
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} '/Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/missing' aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AR = ar
AS = as
AUTOCONF = ${SHELL} '/Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/missing' autoconf
AUTOHEADER = ${SHELL} '/Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/missing' autoheader
AUTOMAKE = ${SHELL} '/Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/missing' automake-1.16
AWK = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/bin/nbawk
CC = cc
CCDEPMODE = depmode=gcc3
CFLAGS = -O -O2 -no-cpp-precomp
CPP = cc -E
CPPFLAGS = -I/Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/include -I/Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/include 
CSCOPE = cscope
CTAGS = ctags
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLTOOL = false
DSYMUTIL = dsymutil
DUMPBIN = 
ECHO_C = \c
ECHO_N = 
ECHO_T = 
EGREP = /usr/bin/grep -E
ETAGS = etags
EXEEXT = 
FGREP = /usr/bin/grep -F
FILECMD = file
GCC_VERSION = 14.0.3
GITVERSION = 
GREP = /usr/bin/grep
HASGIT = 
INSTALL = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/bin/m68k--netbsdelf-install -c  -r
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LD = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld
LDFLAGS = -L/Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/lib -L/Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/lib 
LIBOBJS = 
LIBS = -lmpfr -lgmp -lm 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIPO = lipo
LN_S = ln -s
LTLIBOBJS = 
LT_SYS_LIBRARY_PATH = 
MAINT = #
MAKEINFO = ${SHELL} '/Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/missing' makeinfo
MANIFEST_TOOL = :
MKDIR_P = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64/bin/m68k--netbsdelf-install -d -p
MPC_LDFLAGS = 
MPC_LOG_H = 
NM = /usr/bin/nm -B
NMEDIT = nmedit
OBJDUMP = objdump
OBJEXT = o
OTOOL = otool
OTOOL64 = :
PACKAGE = mpc
PACKAGE_BUGREPORT = mpc-discuss@inria.fr
PACKAGE_NAME = mpc
PACKAGE_STRING = mpc 1.3.1
PACKAGE_TARNAME = mpc
PACKAGE_URL = 
PACKAGE_VERSION = 1.3.1
PATH_SEPARATOR = :
RANLIB = ranlib
SED = /usr/bin/sed
SET_MAKE = 
SHELL = /bin/sh
STRIP = strip
VALGRIND = 
VALGRIND_OPTS = 
VERSION = 1.3.1
abs_builddir = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tools/mpc/build/src
abs_srcdir = /Users/sidqian/Downloads/netbsd-src-trunk/tools/mpc/../../external/lgpl3/mpc/dist/src
abs_top_builddir = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tools/mpc/build
abs_top_srcdir = /Users/sidqian/Downloads/netbsd-src-trunk/tools/mpc/../../external/lgpl3/mpc/dist
ac_ct_AR = 
ac_ct_CC = cc
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-apple-darwin22.1.0
build_alias = 
build_cpu = x86_64
build_os = darwin22.1.0
build_vendor = apple
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-apple-darwin22.1.0
host_alias = 
host_cpu = x86_64
host_os = darwin22.1.0
host_vendor = apple
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /Users/sidqian/Downloads/netbsd-src-trunk/external/lgpl3/mpc/dist/build-aux/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /Users/sidqian/Downloads/netbsd-src-trunk/build/obj/tooldir.Darwin-22.1.0-x86_64
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = /Users/sidqian/Downloads/netbsd-src-trunk/tools/mpc/../../external/lgpl3/mpc/dist/src
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../
top_builddir = ..
top_srcdir = /Users/sidqian/Downloads/netbsd-src-trunk/tools/mpc/../../external/lgpl3/mpc/dist
lib_LTLIBRARIES = libmpc.la
libmpc_la_LDFLAGS = $(MPC_LDFLAGS) -version-info 6:1:3
libmpc_la_SOURCES = mpc-impl.h abs.c acos.c acosh.c add.c add_fr.c         \
  add_si.c add_ui.c agm.c arg.c asin.c asinh.c atan.c atanh.c clear.c      \
  cmp.c cmp_abs.c cmp_si_si.c conj.c cos.c cosh.c                          \
  div_2si.c div_2ui.c div.c div_fr.c div_ui.c				   \
  dot.c eta.c exp.c fma.c fr_div.c fr_sub.c get_prec2.c get_prec.c	   \
  get_version.c get_x.c imag.c init2.c init3.c inp_str.c log.c log10.c     \
  mem.c mul_2si.c mul_2ui.c mul.c mul_fr.c mul_i.c mul_si.c mul_ui.c       \
  neg.c norm.c out_str.c pow.c pow_fr.c                                    \
  pow_ld.c pow_d.c pow_si.c pow_ui.c pow_z.c proj.c real.c rootofunity.c   \
  urandom.c set.c 							   \
  set_prec.c set_str.c set_x.c set_x_x.c sin.c sin_cos.c sinh.c sqr.c      \
  sqrt.c strtoc.c sub.c sub_fr.c sub_ui.c sum.c swap.c tan.c tanh.c        \
  uceil_log2.c ui_div.c ui_ui_sub.c \
  radius.c balls.c

libmpc_la_LIBADD = 
all: all-am

.SUFFIXES:
.SUFFIXES: .c .lo .o .obj
$(srcdir)/Makefile.in: # $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu src/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu src/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure: # $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4): # $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):

install-libLTLIBRARIES: $(lib_LTLIBRARIES)
	@$(NORMAL_INSTALL)
	@list='$(lib_LTLIBRARIES)'; test -n "$(libdir)" || list=; \
	list2=; for p in $$list; do \
	  if test -f $$p; then \
	    list2="$$list2 $$p"; \
	  else :; fi; \
	done; \
	test -z "$$list2" || { \
	  echo " $(MKDIR_P) '$(DESTDIR)$(libdir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(libdir)" || exit 1; \
	  echo " $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL) $(INSTALL_STRIP_FLAG) $$list2 '$(DESTDIR)$(libdir)'"; \
	  $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL) $(INSTALL_STRIP_FLAG) $$list2 "$(DESTDIR)$(libdir)"; \
	}

uninstall-libLTLIBRARIES:
	@$(NORMAL_UNINSTALL)
	@list='$(lib_LTLIBRARIES)'; test -n "$(libdir)" || list=; \
	for p in $$list; do \
	  $(am__strip_dir) \
	  echo " $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=uninstall rm -f '$(DESTDIR)$(libdir)/$$f'"; \
	  $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=uninstall rm -f "$(DESTDIR)$(libdir)/$$f"; \
	done

clean-libLTLIBRARIES:
	-test -z "$(lib_LTLIBRARIES)" || rm -f $(lib_LTLIBRARIES)
	@list='$(lib_LTLIBRARIES)'; \
	locs=`for p in $$list; do echo $$p; done | \
	      sed 's|^[^/]*$$|.|; s|/[^/]*$$||; s|$$|/so_locations|' | \
	      sort -u`; \
	test -z "$$locs" || { \
	  echo rm -f $${locs}; \
	  rm -f $${locs}; \
	}

libmpc.la: $(libmpc_la_OBJECTS) $(libmpc_la_DEPENDENCIES) $(EXTRA_libmpc_la_DEPENDENCIES) 
	$(AM_V_CCLD)$(libmpc_la_LINK) -rpath $(libdir) $(libmpc_la_OBJECTS) $(libmpc_la_LIBADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include $(DEPDIR)/logging.Plo # am--include-marker
include ./$(DEPDIR)/abs.Plo # am--include-marker
include ./$(DEPDIR)/acos.Plo # am--include-marker
include ./$(DEPDIR)/acosh.Plo # am--include-marker
include ./$(DEPDIR)/add.Plo # am--include-marker
include ./$(DEPDIR)/add_fr.Plo # am--include-marker
include ./$(DEPDIR)/add_si.Plo # am--include-marker
include ./$(DEPDIR)/add_ui.Plo # am--include-marker
include ./$(DEPDIR)/agm.Plo # am--include-marker
include ./$(DEPDIR)/arg.Plo # am--include-marker
include ./$(DEPDIR)/asin.Plo # am--include-marker
include ./$(DEPDIR)/asinh.Plo # am--include-marker
include ./$(DEPDIR)/atan.Plo # am--include-marker
include ./$(DEPDIR)/atanh.Plo # am--include-marker
include ./$(DEPDIR)/balls.Plo # am--include-marker
include ./$(DEPDIR)/clear.Plo # am--include-marker
include ./$(DEPDIR)/cmp.Plo # am--include-marker
include ./$(DEPDIR)/cmp_abs.Plo # am--include-marker
include ./$(DEPDIR)/cmp_si_si.Plo # am--include-marker
include ./$(DEPDIR)/conj.Plo # am--include-marker
include ./$(DEPDIR)/cos.Plo # am--include-marker
include ./$(DEPDIR)/cosh.Plo # am--include-marker
include ./$(DEPDIR)/div.Plo # am--include-marker
include ./$(DEPDIR)/div_2si.Plo # am--include-marker
include ./$(DEPDIR)/div_2ui.Plo # am--include-marker
include ./$(DEPDIR)/div_fr.Plo # am--include-marker
include ./$(DEPDIR)/div_ui.Plo # am--include-marker
include ./$(DEPDIR)/dot.Plo # am--include-marker
include ./$(DEPDIR)/eta.Plo # am--include-marker
include ./$(DEPDIR)/exp.Plo # am--include-marker
include ./$(DEPDIR)/fma.Plo # am--include-marker
include ./$(DEPDIR)/fr_div.Plo # am--include-marker
include ./$(DEPDIR)/fr_sub.Plo # am--include-marker
include ./$(DEPDIR)/get_prec.Plo # am--include-marker
include ./$(DEPDIR)/get_prec2.Plo # am--include-marker
include ./$(DEPDIR)/get_version.Plo # am--include-marker
include ./$(DEPDIR)/get_x.Plo # am--include-marker
include ./$(DEPDIR)/imag.Plo # am--include-marker
include ./$(DEPDIR)/init2.Plo # am--include-marker
include ./$(DEPDIR)/init3.Plo # am--include-marker
include ./$(DEPDIR)/inp_str.Plo # am--include-marker
include ./$(DEPDIR)/log.Plo # am--include-marker
include ./$(DEPDIR)/log10.Plo # am--include-marker
include ./$(DEPDIR)/mem.Plo # am--include-marker
include ./$(DEPDIR)/mul.Plo # am--include-marker
include ./$(DEPDIR)/mul_2si.Plo # am--include-marker
include ./$(DEPDIR)/mul_2ui.Plo # am--include-marker
include ./$(DEPDIR)/mul_fr.Plo # am--include-marker
include ./$(DEPDIR)/mul_i.Plo # am--include-marker
include ./$(DEPDIR)/mul_si.Plo # am--include-marker
include ./$(DEPDIR)/mul_ui.Plo # am--include-marker
include ./$(DEPDIR)/neg.Plo # am--include-marker
include ./$(DEPDIR)/norm.Plo # am--include-marker
include ./$(DEPDIR)/out_str.Plo # am--include-marker
include ./$(DEPDIR)/pow.Plo # am--include-marker
include ./$(DEPDIR)/pow_d.Plo # am--include-marker
include ./$(DEPDIR)/pow_fr.Plo # am--include-marker
include ./$(DEPDIR)/pow_ld.Plo # am--include-marker
include ./$(DEPDIR)/pow_si.Plo # am--include-marker
include ./$(DEPDIR)/pow_ui.Plo # am--include-marker
include ./$(DEPDIR)/pow_z.Plo # am--include-marker
include ./$(DEPDIR)/proj.Plo # am--include-marker
include ./$(DEPDIR)/radius.Plo # am--include-marker
include ./$(DEPDIR)/real.Plo # am--include-marker
include ./$(DEPDIR)/rootofunity.Plo # am--include-marker
include ./$(DEPDIR)/set.Plo # am--include-marker
include ./$(DEPDIR)/set_prec.Plo # am--include-marker
include ./$(DEPDIR)/set_str.Plo # am--include-marker
include ./$(DEPDIR)/set_x.Plo # am--include-marker
include ./$(DEPDIR)/set_x_x.Plo # am--include-marker
include ./$(DEPDIR)/sin.Plo # am--include-marker
include ./$(DEPDIR)/sin_cos.Plo # am--include-marker
include ./$(DEPDIR)/sinh.Plo # am--include-marker
include ./$(DEPDIR)/sqr.Plo # am--include-marker
include ./$(DEPDIR)/sqrt.Plo # am--include-marker
include ./$(DEPDIR)/strtoc.Plo # am--include-marker
include ./$(DEPDIR)/sub.Plo # am--include-marker
include ./$(DEPDIR)/sub_fr.Plo # am--include-marker
include ./$(DEPDIR)/sub_ui.Plo # am--include-marker
include ./$(DEPDIR)/sum.Plo # am--include-marker
include ./$(DEPDIR)/swap.Plo # am--include-marker
include ./$(DEPDIR)/tan.Plo # am--include-marker
include ./$(DEPDIR)/tanh.Plo # am--include-marker
include ./$(DEPDIR)/uceil_log2.Plo # am--include-marker
include ./$(DEPDIR)/ui_div.Plo # am--include-marker
include ./$(DEPDIR)/ui_ui_sub.Plo # am--include-marker
include ./$(DEPDIR)/urandom.Plo # am--include-marker

$(am__depfiles_remade):
	@$(MKDIR_P) $(@D)
	@echo '# dummy' >$@-t && $(am__mv) $@-t $@

am--depfiles: $(am__depfiles_remade)

.c.o:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ $<

.c.obj:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.c.lo:
	$(AM_V_CC)$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	$(AM_V_CC)source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(LTCOMPILE) -c -o $@ $<

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags
distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(LTLIBRARIES)
installdirs:
	for dir in "$(DESTDIR)$(libdir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-generic clean-libLTLIBRARIES clean-libtool \
	mostlyclean-am

distclean: distclean-am
		-rm -f $(DEPDIR)/logging.Plo
	-rm -f ./$(DEPDIR)/abs.Plo
	-rm -f ./$(DEPDIR)/acos.Plo
	-rm -f ./$(DEPDIR)/acosh.Plo
	-rm -f ./$(DEPDIR)/add.Plo
	-rm -f ./$(DEPDIR)/add_fr.Plo
	-rm -f ./$(DEPDIR)/add_si.Plo
	-rm -f ./$(DEPDIR)/add_ui.Plo
	-rm -f ./$(DEPDIR)/agm.Plo
	-rm -f ./$(DEPDIR)/arg.Plo
	-rm -f ./$(DEPDIR)/asin.Plo
	-rm -f ./$(DEPDIR)/asinh.Plo
	-rm -f ./$(DEPDIR)/atan.Plo
	-rm -f ./$(DEPDIR)/atanh.Plo
	-rm -f ./$(DEPDIR)/balls.Plo
	-rm -f ./$(DEPDIR)/clear.Plo
	-rm -f ./$(DEPDIR)/cmp.Plo
	-rm -f ./$(DEPDIR)/cmp_abs.Plo
	-rm -f ./$(DEPDIR)/cmp_si_si.Plo
	-rm -f ./$(DEPDIR)/conj.Plo
	-rm -f ./$(DEPDIR)/cos.Plo
	-rm -f ./$(DEPDIR)/cosh.Plo
	-rm -f ./$(DEPDIR)/div.Plo
	-rm -f ./$(DEPDIR)/div_2si.Plo
	-rm -f ./$(DEPDIR)/div_2ui.Plo
	-rm -f ./$(DEPDIR)/div_fr.Plo
	-rm -f ./$(DEPDIR)/div_ui.Plo
	-rm -f ./$(DEPDIR)/dot.Plo
	-rm -f ./$(DEPDIR)/eta.Plo
	-rm -f ./$(DEPDIR)/exp.Plo
	-rm -f ./$(DEPDIR)/fma.Plo
	-rm -f ./$(DEPDIR)/fr_div.Plo
	-rm -f ./$(DEPDIR)/fr_sub.Plo
	-rm -f ./$(DEPDIR)/get_prec.Plo
	-rm -f ./$(DEPDIR)/get_prec2.Plo
	-rm -f ./$(DEPDIR)/get_version.Plo
	-rm -f ./$(DEPDIR)/get_x.Plo
	-rm -f ./$(DEPDIR)/imag.Plo
	-rm -f ./$(DEPDIR)/init2.Plo
	-rm -f ./$(DEPDIR)/init3.Plo
	-rm -f ./$(DEPDIR)/inp_str.Plo
	-rm -f ./$(DEPDIR)/log.Plo
	-rm -f ./$(DEPDIR)/log10.Plo
	-rm -f ./$(DEPDIR)/mem.Plo
	-rm -f ./$(DEPDIR)/mul.Plo
	-rm -f ./$(DEPDIR)/mul_2si.Plo
	-rm -f ./$(DEPDIR)/mul_2ui.Plo
	-rm -f ./$(DEPDIR)/mul_fr.Plo
	-rm -f ./$(DEPDIR)/mul_i.Plo
	-rm -f ./$(DEPDIR)/mul_si.Plo
	-rm -f ./$(DEPDIR)/mul_ui.Plo
	-rm -f ./$(DEPDIR)/neg.Plo
	-rm -f ./$(DEPDIR)/norm.Plo
	-rm -f ./$(DEPDIR)/out_str.Plo
	-rm -f ./$(DEPDIR)/pow.Plo
	-rm -f ./$(DEPDIR)/pow_d.Plo
	-rm -f ./$(DEPDIR)/pow_fr.Plo
	-rm -f ./$(DEPDIR)/pow_ld.Plo
	-rm -f ./$(DEPDIR)/pow_si.Plo
	-rm -f ./$(DEPDIR)/pow_ui.Plo
	-rm -f ./$(DEPDIR)/pow_z.Plo
	-rm -f ./$(DEPDIR)/proj.Plo
	-rm -f ./$(DEPDIR)/radius.Plo
	-rm -f ./$(DEPDIR)/real.Plo
	-rm -f ./$(DEPDIR)/rootofunity.Plo
	-rm -f ./$(DEPDIR)/set.Plo
	-rm -f ./$(DEPDIR)/set_prec.Plo
	-rm -f ./$(DEPDIR)/set_str.Plo
	-rm -f ./$(DEPDIR)/set_x.Plo
	-rm -f ./$(DEPDIR)/set_x_x.Plo
	-rm -f ./$(DEPDIR)/sin.Plo
	-rm -f ./$(DEPDIR)/sin_cos.Plo
	-rm -f ./$(DEPDIR)/sinh.Plo
	-rm -f ./$(DEPDIR)/sqr.Plo
	-rm -f ./$(DEPDIR)/sqrt.Plo
	-rm -f ./$(DEPDIR)/strtoc.Plo
	-rm -f ./$(DEPDIR)/sub.Plo
	-rm -f ./$(DEPDIR)/sub_fr.Plo
	-rm -f ./$(DEPDIR)/sub_ui.Plo
	-rm -f ./$(DEPDIR)/sum.Plo
	-rm -f ./$(DEPDIR)/swap.Plo
	-rm -f ./$(DEPDIR)/tan.Plo
	-rm -f ./$(DEPDIR)/tanh.Plo
	-rm -f ./$(DEPDIR)/uceil_log2.Plo
	-rm -f ./$(DEPDIR)/ui_div.Plo
	-rm -f ./$(DEPDIR)/ui_ui_sub.Plo
	-rm -f ./$(DEPDIR)/urandom.Plo
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-libLTLIBRARIES

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
		-rm -f $(DEPDIR)/logging.Plo
	-rm -f ./$(DEPDIR)/abs.Plo
	-rm -f ./$(DEPDIR)/acos.Plo
	-rm -f ./$(DEPDIR)/acosh.Plo
	-rm -f ./$(DEPDIR)/add.Plo
	-rm -f ./$(DEPDIR)/add_fr.Plo
	-rm -f ./$(DEPDIR)/add_si.Plo
	-rm -f ./$(DEPDIR)/add_ui.Plo
	-rm -f ./$(DEPDIR)/agm.Plo
	-rm -f ./$(DEPDIR)/arg.Plo
	-rm -f ./$(DEPDIR)/asin.Plo
	-rm -f ./$(DEPDIR)/asinh.Plo
	-rm -f ./$(DEPDIR)/atan.Plo
	-rm -f ./$(DEPDIR)/atanh.Plo
	-rm -f ./$(DEPDIR)/balls.Plo
	-rm -f ./$(DEPDIR)/clear.Plo
	-rm -f ./$(DEPDIR)/cmp.Plo
	-rm -f ./$(DEPDIR)/cmp_abs.Plo
	-rm -f ./$(DEPDIR)/cmp_si_si.Plo
	-rm -f ./$(DEPDIR)/conj.Plo
	-rm -f ./$(DEPDIR)/cos.Plo
	-rm -f ./$(DEPDIR)/cosh.Plo
	-rm -f ./$(DEPDIR)/div.Plo
	-rm -f ./$(DEPDIR)/div_2si.Plo
	-rm -f ./$(DEPDIR)/div_2ui.Plo
	-rm -f ./$(DEPDIR)/div_fr.Plo
	-rm -f ./$(DEPDIR)/div_ui.Plo
	-rm -f ./$(DEPDIR)/dot.Plo
	-rm -f ./$(DEPDIR)/eta.Plo
	-rm -f ./$(DEPDIR)/exp.Plo
	-rm -f ./$(DEPDIR)/fma.Plo
	-rm -f ./$(DEPDIR)/fr_div.Plo
	-rm -f ./$(DEPDIR)/fr_sub.Plo
	-rm -f ./$(DEPDIR)/get_prec.Plo
	-rm -f ./$(DEPDIR)/get_prec2.Plo
	-rm -f ./$(DEPDIR)/get_version.Plo
	-rm -f ./$(DEPDIR)/get_x.Plo
	-rm -f ./$(DEPDIR)/imag.Plo
	-rm -f ./$(DEPDIR)/init2.Plo
	-rm -f ./$(DEPDIR)/init3.Plo
	-rm -f ./$(DEPDIR)/inp_str.Plo
	-rm -f ./$(DEPDIR)/log.Plo
	-rm -f ./$(DEPDIR)/log10.Plo
	-rm -f ./$(DEPDIR)/mem.Plo
	-rm -f ./$(DEPDIR)/mul.Plo
	-rm -f ./$(DEPDIR)/mul_2si.Plo
	-rm -f ./$(DEPDIR)/mul_2ui.Plo
	-rm -f ./$(DEPDIR)/mul_fr.Plo
	-rm -f ./$(DEPDIR)/mul_i.Plo
	-rm -f ./$(DEPDIR)/mul_si.Plo
	-rm -f ./$(DEPDIR)/mul_ui.Plo
	-rm -f ./$(DEPDIR)/neg.Plo
	-rm -f ./$(DEPDIR)/norm.Plo
	-rm -f ./$(DEPDIR)/out_str.Plo
	-rm -f ./$(DEPDIR)/pow.Plo
	-rm -f ./$(DEPDIR)/pow_d.Plo
	-rm -f ./$(DEPDIR)/pow_fr.Plo
	-rm -f ./$(DEPDIR)/pow_ld.Plo
	-rm -f ./$(DEPDIR)/pow_si.Plo
	-rm -f ./$(DEPDIR)/pow_ui.Plo
	-rm -f ./$(DEPDIR)/pow_z.Plo
	-rm -f ./$(DEPDIR)/proj.Plo
	-rm -f ./$(DEPDIR)/radius.Plo
	-rm -f ./$(DEPDIR)/real.Plo
	-rm -f ./$(DEPDIR)/rootofunity.Plo
	-rm -f ./$(DEPDIR)/set.Plo
	-rm -f ./$(DEPDIR)/set_prec.Plo
	-rm -f ./$(DEPDIR)/set_str.Plo
	-rm -f ./$(DEPDIR)/set_x.Plo
	-rm -f ./$(DEPDIR)/set_x_x.Plo
	-rm -f ./$(DEPDIR)/sin.Plo
	-rm -f ./$(DEPDIR)/sin_cos.Plo
	-rm -f ./$(DEPDIR)/sinh.Plo
	-rm -f ./$(DEPDIR)/sqr.Plo
	-rm -f ./$(DEPDIR)/sqrt.Plo
	-rm -f ./$(DEPDIR)/strtoc.Plo
	-rm -f ./$(DEPDIR)/sub.Plo
	-rm -f ./$(DEPDIR)/sub_fr.Plo
	-rm -f ./$(DEPDIR)/sub_ui.Plo
	-rm -f ./$(DEPDIR)/sum.Plo
	-rm -f ./$(DEPDIR)/swap.Plo
	-rm -f ./$(DEPDIR)/tan.Plo
	-rm -f ./$(DEPDIR)/tanh.Plo
	-rm -f ./$(DEPDIR)/uceil_log2.Plo
	-rm -f ./$(DEPDIR)/ui_div.Plo
	-rm -f ./$(DEPDIR)/ui_ui_sub.Plo
	-rm -f ./$(DEPDIR)/urandom.Plo
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-libLTLIBRARIES

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am am--depfiles check check-am clean \
	clean-generic clean-libLTLIBRARIES clean-libtool cscopelist-am \
	ctags ctags-am distclean distclean-compile distclean-generic \
	distclean-libtool distclean-tags distdir dvi dvi-am html \
	html-am info info-am install install-am install-data \
	install-data-am install-dvi install-dvi-am install-exec \
	install-exec-am install-html install-html-am install-info \
	install-info-am install-libLTLIBRARIES install-man install-pdf \
	install-pdf-am install-ps install-ps-am install-strip \
	installcheck installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic mostlyclean-libtool pdf pdf-am ps ps-am \
	tags tags-am uninstall uninstall-am uninstall-libLTLIBRARIES

.PRECIOUS: Makefile


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
