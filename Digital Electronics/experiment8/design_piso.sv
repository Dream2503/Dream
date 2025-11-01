// https://www.edaplayground.com/x/a5J3

module PISO(CLK, D2, D1, D0, Q0);
    input CLK, D2, D1, D0;
    output Q0;
    wire Q2, Q1;

    D_flipflop FF0 (CLK, D2, Q2);
    D_flipflop FF1 (CLK, D1, Q1);
    D_flipflop FF2 (CLK, D0, Q0);
endmodule
