// https://www.edaplayground.com/x/qbF2

module SIPO(CLK, SI, Q2, Q1, Q0);
    input CLK, SI;
    output Q2, Q1, Q0;

    D_flipflop FF0 (CLK, SI, Q2);
    D_flipflop FF1 (CLK, Q2, Q1);
    D_flipflop FF2 (CLK, Q1, Q0);
endmodule
