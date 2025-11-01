// https://www.edaplayground.com/x/DnDC

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
