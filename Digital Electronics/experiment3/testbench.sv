// https://www.edaplayground.com/x/GPCH

module implementation_test();
    reg A, B, C;
    wire y_nand, y_nor;

    nand_implementation nand_dut(A, B, C, y_nand);
    nor_implementation nor_dut(A, B, C, y_nor);
  
    initial begin
        A = 0; B = 0; C = 0; #10;
        A = 0; B = 0; C = 1; #10;
        A = 0; B = 1; C = 0; #10;
        A = 0; B = 1; C = 1; #10;
        A = 1; B = 0; C = 0; #10;
        A = 1; B = 0; C = 1; #10;
        A = 1; B = 1; C = 0; #10;
        A = 1; B = 1; C = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
    	$dumpvars(1, implementation_test);
    end
endmodule
