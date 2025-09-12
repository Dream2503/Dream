// https://www.edaplayground.com/x/JPUK

module full_adder_test();
    reg A, B, C;
    wire S, C_out;

    full_adder full_adder_dut(A, B, C, S, C_out);
  
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
        $dumpvars(1, full_adder_test);
    end
endmodule
