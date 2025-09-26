// https://www.edaplayground.com/x/EYUs

module mux_4_to_1_test();
    reg S1, S0, I3, I2, I1, I0;
    wire Y;

    mux_4_to_1 mux_4_to_1_dut(S1, S0, I3, I2, I1, I0, Y);

    initial begin
        S1 = 0; S0 = 0; I3 = 0; I2 = 0; I1 = 0; I0 = 1; #10;
        S1 = 0; S0 = 0; I3 = 0; I2 = 0; I1 = 0; I0 = 0; #10;

        S1 = 0; S0 = 1; I3 = 0; I2 = 0; I1 = 1; I0 = 0; #10;
        S1 = 0; S0 = 1; I3 = 0; I2 = 0; I1 = 0; I0 = 0; #10;

        S1 = 1; S0 = 0; I3 = 0; I2 = 1; I1 = 0; I0 = 0; #10;
        S1 = 1; S0 = 0; I3 = 0; I2 = 0; I1 = 0; I0 = 0; #10;

        S1 = 1; S0 = 1; I3 = 1; I2 = 0; I1 = 0; I0 = 0; #10;
        S1 = 1; S0 = 1; I3 = 0; I2 = 0; I1 = 0; I0 = 0; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, mux_4_to_1_test);
    end
endmodule
