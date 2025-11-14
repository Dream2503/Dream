// https://edaplayground.com/x/Z35b

module half_adder(A, B, S, C_out);
    input A, B;
    output S, C_out;

    assign S = A ^ B;
    assign C_out = A & B;
endmodule

module binary_multiplier(A1, A0, B1, B0, S3, S2, S1, S0);
    input A1, A0, B1, B0;
    output S3, S2, S1, S0;
    wire carry;

    assign S0 = A0 & B0;
    half_adder HA1(A1 & B0, B1 & A0, S1, carry);
    half_adder HA2(carry, B1 & A1, S2, S3);
endmodule
