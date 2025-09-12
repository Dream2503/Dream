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