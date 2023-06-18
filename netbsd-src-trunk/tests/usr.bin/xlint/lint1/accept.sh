#! /bin/sh
# $NetBSD: accept.sh,v 1.11 2022/06/19 11:50:42 rillig Exp $
#
# Copyright (c) 2021 The NetBSD Foundation, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

# usage: accept.sh <pattern>...
#
#	Run one or more lint tests, saving their output in the corresponding
#	.exp files, for incorporating the messages into the .c files as
#	'expect' comments.

set -eu

: "${archsubdir:=$(make -v ARCHSUBDIR)}"
. './t_integration.sh'		# for configure_test_case

done_tests=''
for pattern in "$@"; do
	# shellcheck disable=SC2231
	for cfile in *$pattern*.c; do
		base=${cfile%.*}
		expfile="$base.exp"
		ln_file="$base.exp-ln"

		configure_test_case "$cfile"
		# shellcheck disable=SC2154
		if [ "$skip" = yes ]; then
			continue
		fi

		if [ ! -f "$ln_file" ]; then
			ln_file='/dev/null'
		fi

		# shellcheck disable=SC2154
		# shellcheck disable=SC2086
		if "$lint1" $flags "$base.c" "$ln_file" > "$expfile"; then
			if [ -s "$expfile" ]; then
				echo "$base produces output but exits successfully"
				sed 's,^,| ,' "$expfile"
			fi
		elif [ $? -ge 128 ]; then
			echo "$base crashed"
			continue
		fi

		case "$base" in (msg_*)
			if grep 'This message is not used\.' "$cfile" >/dev/null; then
				: 'Skip further checks.'
			elif [ ! -s "$expfile" ]; then
				echo "$base should produce warnings"
			elif grep '^TODO: "Add example code' "$cfile" >/dev/null; then
				: 'ok, this test is not yet written'
			else
				msgid=${base}
				msgid=${msgid#msg_00}
				msgid=${msgid#msg_0}
				msgid=${msgid#msg_}
				msgid=${msgid%%_*}
				if ! grep "\\[$msgid\\]\$" "$expfile" >/dev/null; then
					echo "$base should trigger the message '$msgid'"
				fi
			fi
		esac

		done_tests="$done_tests $cfile"
	done
done

# shellcheck disable=SC2086
lua './check-expect.lua' $done_tests
