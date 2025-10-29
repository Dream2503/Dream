// https://www.edaplayground.com/x/RXLu

module jk_latch (EN, J, K, Q, not_Q);
    input EN, J, K;
    output reg Q, not_Q;

    always @(EN or J or K) begin
        if (EN) begin
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
        end
        else begin
            {Q, not_Q} <= {Q, not_Q};
        end
    end
endmodule
