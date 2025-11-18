/*	Q3. Declare a class Complex with member real and imaginary part. Define a method initialise() to input the two complex numbers, display() to
        display the complex number and add() to add the two complex numbers. Declare another class to illustrate the operations of the Complex class.
*/

import java.util.Scanner;

class Complex {
    private double real, imag;

    public void initialize(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public void display() {
        System.out.println(real + "+" + imag + "i");
    }

    public static Complex add(Complex complex1, Complex complex2) {
        Complex res = new Complex();
        res.initialize(complex1.real + complex2.real, complex1.imag + complex2.imag);
        return res;
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
    }

    private static Complex createComplex(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter real and imag for " + name + " complex number: ");
        double real = sc.nextDouble();
        double imag = sc.nextDouble();
        Complex complex = new Complex();
        complex.initialize(real, imag);
        return complex;
    }
}
