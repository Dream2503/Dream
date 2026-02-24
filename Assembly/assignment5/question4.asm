; Q4. An assembly program to multiply two numbers.

XRA A
MVI B, 03H
MVI C, 06H

loop: ADD B
DCR C
JNZ loop

STA 0000H
HLT
