// https://www.edaplayground.com/x/8f_4

module demux_4_to_1(S1, S0, I, Y3, Y2, Y1, Y0);
    input S1, S0, I;
    output Y3, Y2, Y1, Y0;
    
    assign Y0 = ~S1 & ~S0 ? I : 0;
    assign Y1 = ~S1 & S0 ? I : 0;
    assign Y2 = S1 & ~S0 ? I : 0;
    assign Y3 = S1 & S0 ? I : 0;
endmodule
