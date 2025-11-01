// https://www.edaplayground.com/x/74hu

module d_latch_test;
    reg EN, D;
    wire Q, not_Q;

    d_latch d_latch_dut (EN, D, Q, not_Q);

    initial begin
        d_latch_dut.Q = 0;
        d_latch_dut.not_Q = 1;
        {EN, D} = 2'b0x; #10;
        {EN, D} = 2'b10; #10;
        {EN, D} = 2'b11; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, d_latch_test);
    end
endmodule
