// https://edaplayground.com/x/Z35b

module binary_multiplier_test();
    reg A1, A0, B1, B0;
    wire S3, S2, S1, S0;

    binary_multiplier binary_multiplier_dut(A1, A0, B1, B0, S3, S2, S1, S0);

    initial begin
        for (int i = 0; i < 16; i++) begin
            {A1, A0, B1, B0} = i[3:0]; #10;
        end
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, binary_multiplier_test);
    end
endmodule
