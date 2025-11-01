// https://www.edaplayground.com/x/8f_4

module demux_4_to_1_test();
    reg S1, S0, I;
    wire Y3, Y2, Y1, Y0;

    demux_4_to_1 demux_4_to_1_dut(S1, S0, I, Y3, Y2, Y1, Y0);

    initial begin
        S1 = 0; S0 = 0; I = 0; #10;
        S1 = 0; S0 = 0; I = 1; #10;
        S1 = 0; S0 = 1; I = 0; #10;
        S1 = 0; S0 = 1; I = 1; #10;
        S1 = 1; S0 = 0; I = 0; #10;
        S1 = 1; S0 = 0; I = 1; #10;
        S1 = 1; S0 = 1; I = 0; #10;
        S1 = 1; S0 = 1; I = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, demux_4_to_1_test);
    end
endmodule
