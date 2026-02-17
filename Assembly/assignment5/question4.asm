; Q4. An assembly program to multiply two numbers.

MVI B, 3
MVI C, 6

loop: ADD B
DCR C
JNZ loop

STA 0
HLT
