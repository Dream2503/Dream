// https://www.edaplayground.com/x/6WLq

module half_subtracter(A, B, D, B_out);
    input A, B;
    output D, B_out;
  	wire a_not;

    xor(D, A, B);
    not(a_not, A);
    and(B_out, a_not, B);
endmodule
