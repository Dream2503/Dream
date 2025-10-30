// https://edaplayground.com/x/PVJs

module t_latch(EN, T, Q, not_Q);
    input EN, T;
    output reg Q, not_Q;

    always @(EN or T) begin
        if (EN) begin
            if (T) begin
                {Q, not_Q} <= {not_Q, Q};
            end
            else begin
                {Q, not_Q} <= {Q, not_Q};
            end
        end
        else begin
            {Q, not_Q} <= {Q, not_Q};
        end
    end
endmodule
