// https://www.edaplayground.com/x/GPCH

module nand_implementation(A, B, C, y);
    input A, B, C;
    output y;
    wire bc;

    // Original Function, F = A' + BC
    // Double negated SOP Function, F = (A(BC'))'
    nand(bc, B, C);
    nand(y, A, bc);
endmodule
