// https://www.edaplayground.com/x/NsXv

module level_two_minimization(A, B, C, y);
    input A, B, C;
    output y;
    wire ac, not_b;

    // Original Function, F = AB' + B'C + AB'C
    // Minimized Function, F = B'(A + C)
    not(not_b, B);
    or(ac, A, C);
    and(y, not_b, ac);
endmodule
