// https://www.edaplayground.com/x/G_cH

module basic_test();
    reg A, B;
    wire y_not1, y_and1, y_or1, y_nand1, y_nor1, y_xor1, y_xnor1;
    wire y_not2, y_and2, y_or2, y_nand2, y_nor2, y_xor2, y_xnor2;
    wire y_not3, y_and3, y_or3, y_nand3, y_nor3, y_xor3, y_xnor3;

    basic_gates basic_dut(A, B, y_not1, y_and1, y_or1, y_nand1, y_nor1, y_xor1, y_xnor1);
    nand_basic_gates nand_dut(A, B, y_not2, y_and2, y_or2, y_nand2, y_nor2, y_xor2, y_xnor2);
    nor_basic_gates nor_dut(A, B, y_not3, y_and3, y_or3, y_nand3, y_nor3, y_xor3, y_xnor3);
  
    initial begin
        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
    	$dumpvars(1, basic_test);
    end
endmodule