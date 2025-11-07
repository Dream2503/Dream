// https://www.edaplayground.com/x/m5M9

module posedge_3bit_up_counter_test();
    reg CLK, not_RST, not_PRE;
    wire Q0, Q1, Q2;

    posedge_3bit_up_counter posedge_3bit_up_counter_dut(CLK, not_RST, not_PRE, Q0, Q1, Q2);

    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;
    end
    initial begin
        not_RST = 0; not_PRE = 1; #10;
        not_RST = 1; not_PRE = 1; #80;
        $finish;
    end
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, posedge_3bit_up_counter_test);
    end
endmodule
