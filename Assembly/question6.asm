; Q6. Factorial of a number

MVI B, 5
MVI A, 1 

factorial: MOV C, B
MOV D, A
XRA A

multiply: ADD D
DCR C
JNZ multiply
DCR B

JNZ factorial

STA 0
HLT