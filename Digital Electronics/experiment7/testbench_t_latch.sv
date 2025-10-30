// https://edaplayground.com/x/PVJs

module t_latch_test;
    reg EN, T;
    wire Q, not_Q;

    t_latch t_latch_dut (EN, T, Q, not_Q);

    initial begin
        t_latch_dut.Q = 0;
      	t_latch_dut.not_Q = 1;
        {EN, T} = 2'b0x; #10;
        {EN, T} = 2'b10; #10;
        {EN, T} = 2'b11; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, t_latch_test);
    end
endmodule
