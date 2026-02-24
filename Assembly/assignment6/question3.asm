; Q3. WAP to find the largest element of the array.

XRA A
MVI C, 05H
LXI H, 0834H

loop: MOV B, M
CMP B

JP continue
MOV A, B

continue: INX H
DCR C
JNZ loop

INX H
MOV M, A
HLT
