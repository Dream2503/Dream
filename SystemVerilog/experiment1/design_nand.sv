// https://www.edaplayground.com/x/Gyp5

module nand_basic_gates(A, B, y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor);
    input A, B;
    output y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor;
    wire and_ab, or_a_not, or_b_not, xor_ab, xor_a_ab, xor_b_ab;

    // NOT
    nand(y_not, A, A);

    // AND
    nand(and_ab, A, B);
    nand(y_and, and_ab, and_ab);

    // OR
    nand(or_a_not, A, A);
    nand(or_b_not, B, B);
    nand(y_or, or_a_not, or_b_not);

    // NAND
    nand(y_nand, A, B);

    // NOR
    nand(y_nor, y_or, y_or);

    // XOR
    nand(xor_ab, A, B);
    nand(xor_a_ab, A, xor_ab);
    nand(xor_b_ab, B, xor_ab);
    nand(y_xor, xor_a_ab, xor_b_ab);

    // XNOR
    nand(y_xnor, y_xor, y_xor);
endmodule