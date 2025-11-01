// https://www.edaplayground.com/x/JxVE

module PIPO_test;
    reg CLK, D2, D1, D0;
    wire Q2, Q1, Q0;

    PIPO PIPO_dut (CLK, D2, D1, D0, Q2, Q1, Q0);

    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;
    end
    
    initial begin
        {D2, D1, D0} = 3'b000; #10;
        {D2, D1, D0} = 3'b100; #10;
        {D2, D1, D0} = 3'b110; #10;
        {D2, D1, D0} = 3'b011; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, PIPO_test);
    end
endmodule
