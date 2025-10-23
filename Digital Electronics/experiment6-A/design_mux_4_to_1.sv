// https://www.edaplayground.com/x/EYUs

module mux_4_to_1(S1, S0, I3, I2, I1, I0, Y);
    input S1, S0, I3, I2, I1, I0;
    output Y;

    assign Y = ~S1 ? (~S0 ? I0 : I1) : (~S0 ? I2 : I3);
endmodule
