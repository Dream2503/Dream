// https://www.edaplayground.com/x/NsXv

module level_two_minimization(A, B, C, y);
    input A, B, C;
    output y;
    wire ac, not_b;

    // F = AB' + B'C + AB'C
    // F = B'(A + C)
    not(not_b, B);
    or(ac, A, C);
    and(y, not_b, ac);
endmodule

module level_three_minimization(A, B, C, y);
    input A, B, C;
    output y;
    wire bc, not_a, b_xor_c, not_a_b_xor_c;

    // F = A'BC + A'B'C + A'BC'
    // F = BC + A'(B ^ C)
    and(bc, B, C);
    not(not_a, A);
    xor(b_xor_c, B, C);
    and(not_a_b_xor_c, not_a, b_xor_c);
    or(y, bc, not_a_b_xor_c);
endmodule
