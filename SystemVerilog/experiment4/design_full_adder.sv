// https://www.edaplayground.com/x/JPUK

module full_adder(A, B, C, S, C_out);
    input A, B, C;
    output S, C_out;
    wire a_xor_b, or1, or2;

    xor(a_xor_b, A, B);
    xor(S, a_xor_b, C);
    and(or1, a_xor_b, C);
    and(or2, A, B);
    or(C_out, or1, or2);
endmodule
