; Q5. Program to find square of 8-bit number.

MVI B, 7
MOV C, B

loop: ADD B
DCR C
JNZ loop

STA 0
HLT
