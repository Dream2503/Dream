// https://www.edaplayground.com/x/BQZc

module binary_to_gray(B2, B1, B0, G2, G1, G0);
    input B2, B1, B0;
    output G2, G1, G0;
    
    xor(G0, B0, B1);
    xor(G1, B1, B2);
    buf(G2, B2);
endmodule