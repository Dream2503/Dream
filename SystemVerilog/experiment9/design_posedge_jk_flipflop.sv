module posedge_jk_flipflop (CLK, not_RST, not_PRE, {J, K}, Q, not_Q);
    input CLK, not_RST, not_PRE, J, K;
    output reg Q, not_Q;

    always @(posedge CLK or negedge not_RST or negedge not_PRE) begin
        if (not_RST & not_PRE) begin
            case ({J, K})
            2'b00:
                {Q, not_Q} <= {Q, not_Q};

            2'b01:
                {Q, not_Q} <= 2'b01;

            2'b10:
                {Q, not_Q} <= 2'b10;

            2'b11:
                {Q, not_Q} <= {not_Q, Q};
            endcase
        end else if (~not_RST) begin
            {Q, not_Q} <= 2'b01;      
        end else begin
            {Q, not_Q} <= 2'b10;
        end
    end
endmodule
