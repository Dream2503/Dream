// https://www.edaplayground.com/x/n9uv

module posedge_3bit_down_counter(CLK, not_RST, not_PRE, Q0, Q1, Q2);
    input CLK, not_RST, not_PRE;
    output reg Q0, Q1, Q2;
    wire not_Q0, not_Q1, not_Q2;

    posedge_jk_flipflop FF2(CLK, not_RST, not_PRE, 2'b11, Q0, not_Q0);
    posedge_jk_flipflop FF1(Q0, not_RST, not_PRE, 2'b11, Q1, not_Q1);
    posedge_jk_flipflop FF0(Q1, not_RST, not_PRE, 2'b11, Q2, not_Q2);
endmodule
