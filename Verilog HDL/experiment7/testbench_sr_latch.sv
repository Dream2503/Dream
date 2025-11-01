// https://www.edaplayground.com/x/b9Ey

module sr_latch_test;
    reg EN, S, R;
    wire Q, not_Q;

    sr_latch sr_latch_dut (EN, S, R, Q, not_Q);

    initial begin
        sr_latch_dut.Q = 0;
        sr_latch_dut.not_Q = 1;
        {EN, S, R} = 3'b0xx; #10;
        {EN, S, R} = 3'b100; #10;
        {EN, S, R} = 3'b101; #10;
        {EN, S, R} = 3'b110; #10;
        {EN, S, R} = 3'b111; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, sr_latch_test);
    end
endmodule
