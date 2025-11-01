// https://www.edaplayground.com/x/b9Ey

module sr_latch (EN, S, R, Q, not_Q);
    input EN, S, R;
    output reg Q, not_Q;

    always @(EN or S or R) begin
        if (EN) begin
            case ({S, R})
            2'b00:
                {Q, not_Q} <= {Q, not_Q};

            2'b01:
                {Q, not_Q} <= 2'b01;

            2'b10:
                {Q, not_Q} <= 2'b10;

            2'b11:
                {Q, not_Q} <= 2'bxx;
            endcase
        end
        else begin
            {Q, not_Q} <= {Q, not_Q};
        end
    end
endmodule
