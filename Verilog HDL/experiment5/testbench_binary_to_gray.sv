// https://www.edaplayground.com/x/BQZc

module binary_to_gray_test();
    reg B2, B1, B0;
    wire G2, G1, G0;

    binary_to_gray binary_to_gray_dut(B2, B1, B0, G2, G1, G0);
  
    initial begin
        B2 = 0; B1 = 0; B0 = 0; #10;
        B2 = 0; B1 = 0; B0 = 1; #10;
        B2 = 0; B1 = 1; B0 = 0; #10;
        B2 = 0; B1 = 1; B0 = 1; #10;
        B2 = 1; B1 = 0; B0 = 0; #10;
        B2 = 1; B1 = 0; B0 = 1; #10;
        B2 = 1; B1 = 1; B0 = 0; #10;
        B2 = 1; B1 = 1; B0 = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, binary_to_gray_test);
    end
endmodule
