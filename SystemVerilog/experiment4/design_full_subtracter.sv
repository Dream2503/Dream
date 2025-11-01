// https://www.edaplayground.com/x/snCU

module full_subtractor(A, B, C, D, B_out);
    input A, B, C;
    output D, B_out;
    wire a_xor_b,not_a_xor_b, not_a, or1, or2;

    xor(a_xor_b, A, B);
    xor(D, a_xor_b, C);
    not(not_a_xor_b, a_xor_b);
    and(or1, not_a_xor_b, C);
    not(not_a, A);
    and(or2, not_a, B);
    or(B_out, or1, or2);
endmodule
