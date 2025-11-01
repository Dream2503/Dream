// https://www.edaplayground.com/x/JxVE

module PIPO(CLK, D2, D1, D0, Q2, Q1, Q0);
    input CLK, D2, D1, D0;
    output Q2, Q1, Q0;

    D_flipflop FF0 (CLK, D2, Q2);
    D_flipflop FF1 (CLK, D1, Q1);
    D_flipflop FF2 (CLK, D0, Q0);
endmodule
