// https://www.edaplayground.com/x/ZVpp

module demux_2_to_1_test();
    reg S, I;
    wire Y1, Y0;

    demux_2_to_1 demux_2_to_1_dut(S, I, Y1, Y0);

    initial begin
        S = 0; I = 0; #10;
        S = 0; I = 1; #10;
        S = 1; I = 0; #10;
        S = 1; I = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, demux_2_to_1_test);
    end
endmodule
