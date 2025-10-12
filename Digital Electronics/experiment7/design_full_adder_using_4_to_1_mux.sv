// https://www.edaplayground.com/x/R7hM

module mux_4_to_1(EN, S, I, Y);
    input EN;
    input [1:0]S;
    input [0:3]I;
    output Y;

    assign Y = ~EN ? (~S[1] ? (~S[0] ? I[0] : I[1]) : (~S[0] ? I[2] : I[3])) : 0;
endmodule

module full_adder_using_4_to_1_mux(A, B, C, S, C_out);
    input A, B, C;
    output S, C_out;
  
  	mux_4_to_1 sum(1'b0, {A, B}, {C, ~C, ~C, C}, S);
  	mux_4_to_1 carry(1'b0, {A, B}, {1'b0, C, C, 1'b1}, C_out);
endmodule
