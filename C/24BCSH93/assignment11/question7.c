#include <stdio.h>

typedef struct COMPLEX {
	float real, imag;
} COMPLEX;

COMPLEX ADDCOMPLEX(COMPLEX, COMPLEX);

int main() {
	COMPLEX c1, c2, res;
	printf("Enter the real and imag value of complex number 1: ");
	scanf("%f%f", &c1.real, &c1.imag);
	printf("Enter the real and imag value of complex number 2: ");
	scanf("%f%f", &c2.real, &c2.imag);
	res = ADDCOMPLEX(c1, c2);
	printf("Addition of %.2f + %.2fi and %.2f + %.2fi is %.2f + %.2fi\n", c1.real, c1.imag, c2.real, c2.imag, res.real, res.imag);
	return 0;
}

COMPLEX ADDCOMPLEX(COMPLEX c1, COMPLEX c2) {
	COMPLEX res;
	res.real = c1.real + c2.real;
	res.imag = c1.imag + c2.imag;
	return res;
}
