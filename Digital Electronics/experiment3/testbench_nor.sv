// https://www.edaplayground.com/x/phSw

module nor_test();
    reg A, B, C;
    wire y_nor;

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
    	$dumpvars(1, nor_test);
    end
endmodule
