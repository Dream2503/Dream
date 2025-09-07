/*	Q3. Define a class Complex, placed the necessary data members and member functions to perform basic Complex number operation. (Note: the class
        must have constructor)
 */

import java.util.Scanner;

class Complex {
    private double real, imag;

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public void display() {
        System.out.println(real + " + " + imag + "i");
    }

    public static Complex add(Complex complex1, Complex complex2) {
        return new Complex(complex1.real + complex2.real, complex1.imag + complex2.imag);
    }

    public static Complex subtract(Complex complex1, Complex complex2) {
        return new Complex(complex1.real - complex2.real, complex1.imag - complex2.imag);
    }
}

class Main {
    public static void main(String[] args) {
        Complex complex1 = createComplex("first");
        Complex complex2 = createComplex("second");
        System.out.println("The two complex numbers are: ");
        complex1.display();
        complex2.display();

        Complex sum = Complex.add(complex1, complex2);
        System.out.print("Sum of two complex numbers is: ");
        sum.display();

        Complex difference = Complex.subtract(complex1, complex2);
        System.out.print("Difference of two complex numbers is: ");
        difference.display();
    }

    private static Complex createComplex(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter real and imag for " + name + " complex number: ");
        double real = sc.nextDouble();
        double imag = sc.nextDouble();
        return new Complex(real, imag);
    }
}
