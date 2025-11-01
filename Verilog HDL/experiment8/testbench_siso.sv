// https://www.edaplayground.com/x/vwxS

module SISO_test;
    reg CLK, SI;
    wire Q0;

    SISO SISO_dut (CLK, SI, Q0);

    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;
    end
    
    initial begin
        SI = 0; #10;
        SI = 0; #10;
        SI = 0; #10;
        SI = 1; #10;
        SI = 1; #10;
        SI = 0; #10;
        $finish;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(1, SISO_test);
    end
endmodule
