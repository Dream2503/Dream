// https://www.edaplayground.com/x/Gyp5

module nand_basic_test();
    reg A, B;
    wire y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor;

    nand_basic_gates nand_dut(A, B, y_not, y_and, y_or, y_nand, y_nor, y_xor, y_xnor);
  
    initial begin
        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
    	$dumpvars(1, nand_basic_test);
    end
endmodule