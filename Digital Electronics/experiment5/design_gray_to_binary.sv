// https://www.edaplayground.com/x/p73X

module gray_to_binary(G2, G1, G0, B2, B1, B0);
    input G2, G1, G0;
    output B2, B1, B0;
    wire g0_xor_g1;
    
    xor(g0_xor_g1, G0, G1);
    xor(B0, g0_xor_g1, G2);
    xor(B1, G1, G2);
    buf(B2, G2);
endmodule
