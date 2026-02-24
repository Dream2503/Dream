; Q2. Assembly Program to Find Smallest of Two 8-bit Numbers.

MVI A, 69H
MVI B, 96H
CMP B

JM small
MOV A, B

small: STA 0000H
HLT
