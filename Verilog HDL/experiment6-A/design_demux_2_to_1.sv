// https://www.edaplayground.com/x/ZVpp

module demux_2_to_1(S, I, Y1, Y0);
    input S, I;
    output Y1, Y0;

    assign Y1 = S ? I : 0;
    assign Y0 = ~S ? I : 0;
endmodule
