# This file is automatically generated.  DO NOT EDIT!
# Generated from: NetBSD: mknative-gcc,v 1.92 2018/02/06 07:04:01 mrg Exp 
# Generated from: NetBSD: mknative.common,v 1.16 2018/04/15 15:13:37 christos Exp 
#
# This spec file is read by gcc when linking.  It is used to specify the
# standard libraries we need in order to link with libgomp.
*link_gomp: -lgomp %{static: }