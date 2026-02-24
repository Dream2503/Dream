; Q5. Program to find square of 8-bit number.

XRA A
MVI B, 07H
MOV C, B

loop: ADD B
DCR C
JNZ loop

STA 0000H
HLT
