// https://www.edaplayground.com/x/NsXv

module minimization_test();
    reg A, B, C;
    wire y_two, y_three;

    level_two_minimization two_dut(A, B, C, y_two);
    level_three_minimization three_dut(A, B, C, y_three);
  
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
    	$dumpvars(1, minimization_test);
    end
endmodule
