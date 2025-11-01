// https://www.edaplayground.com/x/R7hM

module full_adder_using_4_to_1_mux_test();
    reg A, B, C;
    wire S, C_out;

    full_adder_using_4_to_1_mux full_adder_using_4_to_1_mux_dut(A, B, C, S, C_out);
  
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
        $dumpvars(1, full_adder_using_4_to_1_mux_test);
    end
endmodule
