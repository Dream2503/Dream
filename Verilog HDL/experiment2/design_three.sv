// https://www.edaplayground.com/x/K373

module level_three_minimization(A, B, C, y);
    input A, B, C;
    output y;
    wire bc, not_a, b_xor_c, not_a_b_xor_c;

    // Original Function, F = A'BC + A'B'C + A'BC'
    // Minimized Function, F = BC + A'(B ^ C)
    and(bc, B, C);
    not(not_a, A);
    xor(b_xor_c, B, C);
    and(not_a_b_xor_c, not_a, b_xor_c);
    or(y, bc, not_a_b_xor_c);
endmodule
