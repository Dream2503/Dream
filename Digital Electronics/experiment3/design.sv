// https://www.edaplayground.com/x/GPCH

module nand_implementation(A, B, C, y);
    input A, B, C;
    output y;
    wire bc;

    // F = A' + BC
    // F = (A(BC'))'
    nand(bc, B, C);
    nand(y, A, bc);
endmodule

module nor_implementation(A, B, C, y);
    input A, B, C;
    output y;
    wire not_a, not_a_nor_b, not_a_nor_c;

    // F = A' + BC
    // F = ((A' + B)' + (A' + C)')'
    nor(not_a, A, A);
    nor(not_a_nor_b, not_a, B);
    nor(not_a_nor_c, not_a, C);
    nor(y, not_a_nor_b, not_a_nor_c);
endmodule
