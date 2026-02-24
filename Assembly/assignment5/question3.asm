; Q3. An assembly program to add two 8-bit Hexadecimal numbers and store result in decimal form only which will be a 16-bits number.
;     Sample data:
;     A: 84H
;     B: 75H
;     Result = 84H + 75H = F9H = 159D
;     The result stored at 2020H and 2021H.

MVI A, 84H
MVI B, 75H
ADD B
DAA
STA 2021H
XRA A
ADC A
MVI A, 01H
STA 2020H
HLT