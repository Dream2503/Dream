// https://www.edaplayground.com/x/AEi6

module half_adder(A, B, S, C_out);
    input A, B;
    output S, C_out;

  	xor(S, A, B);
    and(C_out, A, B);
endmodule
