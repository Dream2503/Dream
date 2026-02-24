; Q4. Write a program to sort given 10 numbers from memory location 2100H to 2109H in the ascending order.

MVI B, 09H

outer_loop: MVI A, 09H
ADD B
SBI 09H
MOV C, A
LXI H, 2100H

inner_loop: MOV A, M
INX H
MOV D, M
CMP D

JM continue
MOV A, M
DCX H
MOV E, M
MOV M, A
INX H
MOV M, E

continue: DCR C
JNZ inner_loop

DCR B
JNZ outer_loop
HLT
