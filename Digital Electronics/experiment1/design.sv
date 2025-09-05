// https://www.edaplayground.com/x/G_cH

module basic_gates(A, B, y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor);
    input A, B;
    output y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor;

    not(y_not, A);
    and(y_and, A, B);
    or(y_or, A, B);
    nand(y_nand, A, B);
    nor(y_nor, A, B);
    xor(y_xor, A, B);
    xnor(y_xnor, A, B);
endmodule

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

module nor_basic_gates(A, B, y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor);
    input A, B;
    output y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor;
    wire and_a_not, and_b_not, or_ab, xnor_ab, xnor_a_ab, xnor_b_ab;

    // NOT
    nor(y_not, A, A);

    // AND
    nor(and_a_not, A, A);
    nor(and_b_not, B, B);
    nor(y_and, and_a_not, and_b_not);

    // OR
    nor(or_ab, A, B);
    nor(y_or, or_ab, or_ab);

    // NAND
    nor(y_nand, y_and, y_and);

    // NOR
    nor(y_nor, A, B);

    // XOR
    nor(y_xor, y_xnor, y_xnor);

    // XNOR
    nor(xnor_ab, A, B);
    nor(xnor_a_ab, A, xnor_ab);
    nor(xnor_b_ab, B, xnor_ab);
    nor(y_xnor, xnor_a_ab, xnor_b_ab);
endmodule
