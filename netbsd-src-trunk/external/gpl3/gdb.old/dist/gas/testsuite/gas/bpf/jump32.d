#as: --EL
#objdump: -dr
#name: eBPF JUMP32 instructions

.*: +file format .*bpf.*

Disassembly of section .text:

0+ <.text>:
   0:	05 00 03 00 00 00 00 00 	ja 3
   8:	0f 11 00 00 00 00 00 00 	add %r1,%r1
  10:	16 03 01 00 03 00 00 00 	jeq32 %r3,3,1
  18:	1e 43 00 00 00 00 00 00 	jeq32 %r3,%r4,0
  20:	36 03 fd ff 03 00 00 00 	jge32 %r3,3,-3
  28:	3e 43 fc ff 00 00 00 00 	jge32 %r3,%r4,-4
  30:	a6 03 01 00 03 00 00 00 	jlt32 %r3,3,1
  38:	ae 43 00 00 00 00 00 00 	jlt32 %r3,%r4,0
  40:	b6 03 01 00 03 00 00 00 	jle32 %r3,3,1
  48:	be 43 00 00 00 00 00 00 	jle32 %r3,%r4,0
  50:	46 03 01 00 03 00 00 00 	jset32 %r3,3,1
  58:	4e 43 00 00 00 00 00 00 	jset32 %r3,%r4,0
  60:	56 03 01 00 03 00 00 00 	jne32 %r3,3,1
  68:	5e 43 00 00 00 00 00 00 	jne32 %r3,%r4,0
  70:	66 03 01 00 03 00 00 00 	jsgt32 %r3,3,1
  78:	6e 43 00 00 00 00 00 00 	jsgt32 %r3,%r4,0
  80:	76 03 01 00 03 00 00 00 	jsge32 %r3,3,1
  88:	7e 43 00 00 00 00 00 00 	jsge32 %r3,%r4,0
  90:	c6 03 01 00 03 00 00 00 	jslt32 %r3,3,1
  98:	ce 43 00 00 00 00 00 00 	jslt32 %r3,%r4,0
  a0:	d6 03 01 00 03 00 00 00 	jsle32 %r3,3,1
  a8:	de 43 00 00 00 00 00 00 	jsle32 %r3,%r4,0