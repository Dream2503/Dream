// https://www.edaplayground.com/x/74hu

module d_latch(EN, D, Q, not_Q);
    input EN, D;
    output reg Q, not_Q;

    always @(EN or D) begin
        if (EN) begin
            {Q, not_Q} <= {D, ~D};
        end
        else begin
            {Q, not_Q} <= {Q, not_Q};
        end
    end 
endmodule
