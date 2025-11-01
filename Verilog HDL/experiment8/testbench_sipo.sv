// https://www.edaplayground.com/x/qbF2

module SIPO_test;
    reg CLK, SI;
    wire Q2, Q1, Q0;

    SIPO SIPO_dut (CLK, SI, Q2, Q1, Q0);

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
        $dumpvars(1, SIPO_test);
    end
endmodule
