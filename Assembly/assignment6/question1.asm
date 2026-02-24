; Q1. Assembly Program to Find Largest of Two 8-bit Numbers.

MVI A, 69H
MVI B, 96H
CMP B

JP large
MOV A, B

large: STA 0000H
HLT
