; Q6. Program to find sum of digit of an 8-bit number.

MVI B, 69H
MOV A, B
ANI 0FH
MOV C, A
MOV A, B
MVI D, 04H

loop: RRC
DCR D
JNZ loop

ANI 0FH
ADD C
STA 0000H
HLT
