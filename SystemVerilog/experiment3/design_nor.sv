// https://www.edaplayground.com/x/phSw

module nor_implementation(A, B, C, y);
    input A, B, C;
    output y;
    wire not_a, not_a_nor_b, not_a_nor_c;

    // Original Function, F = A' + BC
    // Double negated POS Function, F = ((A' + B)' + (A' + C)')'
    nor(not_a, A, A);
    nor(not_a_nor_b, not_a, B);
    nor(not_a_nor_c, not_a, C);
    nor(y, not_a_nor_b, not_a_nor_c);
endmodule
