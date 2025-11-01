// https://www.edaplayground.com/x/wzCH

module mux_2_to_1(S, I1, I0, Y);
    input S, I1, I0;
    output Y;

    assign Y = ~S ? I0 : I1;
endmodule
