BEGIN {
	print "/*	$NetBSD: make-errno-d.awk,v 1.1 2020/03/08 22:11:48 mgorny Exp $	*/"
	print ""
	print "/*"
	print " * This file is autogenerated.  Please call:"
	print " *   awk make-errno-d.awk < ../../../../../sys/sys/errno.h"
	print " * to get new data."
	print " */"
	print ""
	print "/*"
	print " * CDDL HEADER START"
	print " *"
	print " * The contents of this file are subject to the terms of the"
	print " * Common Development and Distribution License, Version 1.0 only"
	print " * (the \"License\").  You may not use this file except in compliance"
	print " * with the License."
	print " *"
	print " * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE"
	print " * or http://www.opensolaris.org/os/licensing."
	print " * See the License for the specific language governing permissions"
	print " * and limitations under the License."
	print " *"
	print " * When distributing Covered Code, include this CDDL HEADER in each"
	print " * file and include the License file at usr/src/OPENSOLARIS.LICENSE."
	print " * If applicable, add the following below this CDDL HEADER, with the"
	print " * fields enclosed by brackets \"[]\" replaced with your own identifying"
	print " * information: Portions Copyright [yyyy] [name of copyright owner]"
	print " *"
	print " * CDDL HEADER END"
	print " *"
	print " * Portions Copyright 2006-2008 John Birrell jb@freebsd.org"
	print " *"
	print " * $FreeBSD: head/cddl/lib/libdtrace/errno.d 179189 2008-05-22 04:26:42Z jb $"
	print " */"
	print "/*"
	print " * Copyright 2004 Sun Microsystems, Inc.  All rights reserved."
	print " * Use is subject to license terms."
	print " */"
	print ""
}

/^#define\s*E/ {
	print "inline int " $2 " = " $3 ";"
	print "#pragma D binding \"1.0\" " $2
}