// https://www.edaplayground.com/x/wzCH

module mux_2_to_1_test();
    reg S, I1, I0;
    wire Y;

    mux_2_to_1 mux_2_to_1_dut(S, I1, I0, Y);

    initial begin
        S = 0; I1 = 0; I0 = 0; #10;
        S = 0; I1 = 0; I0 = 1; #10;
        S = 0; I1 = 1; I0 = 0; #10;
        S = 0; I1 = 1; I0 = 1; #10;
        S = 1; I1 = 0; I0 = 0; #10;
        S = 1; I1 = 0; I0 = 1; #10;
        S = 1; I1 = 1; I0 = 0; #10;
        S = 1; I1 = 1; I0 = 1; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, mux_2_to_1_test);
    end
endmodule
