// https://www.edaplayground.com/x/snCU

module full_subtracter_test();
    reg A, B, C;
    wire D, B_out;

    full_subtracter full_subtracter_dut(A, B, C, D, B_out);
  
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
        $dumpvars(1, full_subtracter_test);
    end
endmodule
