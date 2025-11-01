// https://www.edaplayground.com/x/6WLq

module half_subtracter_test();
    reg A, B;
    wire D, B_out;

    half_subtracter half_subtracter_dut(A, B, D, B_out);
  
    initial begin
        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
    	$dumpvars(1, half_subtracter_test);
    end
endmodule
