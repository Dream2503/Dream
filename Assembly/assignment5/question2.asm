; Q2. Write a program in 8085 assembly language to perform the following operations:
;     a.  Initialize Register B with 80H
;     b.  Initialize Register D with 84H
;     c.  Add contents of register B and D
;     d.  If the add operation generate an carry then:
;             - store the carry bit in memory location 2021H and 8-bit sum in 2020H memory location.
;         else
;             - store only the 8-bit sum in 2021H memory location.

MVI B, 80H
MVI D, 84H
ADD B
ADD D

JNC else
STA 2020H
MVI A, 1
STA 2021H
HLT

else: STA 2021H
HLT
