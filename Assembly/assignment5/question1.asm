; Q1. Write a program in 8085 assembly language to perform the following operations:
;     a.  Initialize Register B with some data in Hex form
;     b.  Initialize Register C with some data in Hex form
;     c.  Initialize Register D with some data in Hex form
;     d.  Add contents of register B and D
;     e.  If the sum is zero then:
;         - increment the content of register C by 1
;     else
;         - decrement the content of register C by 1

MVI B, 15H
MVI C, 30H
MVI D, 45H
ADD B
ADD D

JNZ else
INR C
HLT

else: DCR C
HLT
