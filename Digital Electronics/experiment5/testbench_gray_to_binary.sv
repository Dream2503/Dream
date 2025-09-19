// https://www.edaplayground.com/x/p73X

module gray_to_binary_test();
    reg G2, G1, G0;
    wire B2, B1, B0;

    gray_to_binary gray_to_binary_dut(G2, G1, G0, B2, B1, B0);
  
    initial begin
        G2 = 0; G1 = 0; G0 = 0; #10;
        G2 = 0; G1 = 0; G0 = 1; #10;
        G2 = 0; G1 = 1; G0 = 0; #10;
        G2 = 0; G1 = 1; G0 = 1; #10;
        G2 = 1; G1 = 0; G0 = 0; #10;
        G2 = 1; G1 = 0; G0 = 1; #10;
        G2 = 1; G1 = 1; G0 = 0; #10;
        G2 = 1; G1 = 1; G0 = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, gray_to_binary_test);
    end
endmodule
