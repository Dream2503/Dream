// https://www.edaplayground.com/x/RXLu

module jk_latch_test;
    reg EN, J, K;
    wire Q, not_Q;

    jk_latch jk_latch_dut (EN, J, K, Q, not_Q);

    initial begin
        jk_latch_dut.Q = 0;
        jk_latch_dut.not_Q = 1;
        {EN, J, K} = 3'b0xx; #10;
        {EN, J, K} = 3'b100; #10;
        {EN, J, K} = 3'b101; #10;
        {EN, J, K} = 3'b110; #10;
        {EN, J, K} = 3'b111; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, jk_latch_test);
    end
endmodule
