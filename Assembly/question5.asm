; Q5. Generate n fibonnaci numbers

MVI C, 10
LXI H, 0

MVI M, 0
DCR C
INX H
MVI M, 1
DCR C

loop: MOV A, M
DCX H
ADD M
INX H
INX H
MOV M, A
DCR C
JNZ loop

HLT
