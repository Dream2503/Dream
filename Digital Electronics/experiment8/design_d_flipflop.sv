module D_flipflop(CLK, D, Q);
    input CLK, D;
    output reg Q;

    always @(posedge CLK) begin
        Q <= D;
    end 
endmodule
