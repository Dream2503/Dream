#include<iostream>
using namespace std;

class Rational {
    private:
        int numerator, denominator;

    public:
        Rational(int numerator = 1,int denominator = 1) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        Rational(Rational &rational) {
            this->numerator = rational.numerator;
            this->denominator = rational.denominator;
        }
        int getNumerator() {return numerator;}
        int getDenominator() {return denominator;}
        void setNumerator(int numerator) {this->numerator = numerator;}
        void setDenominator(int denominator) {this->denominator = denominator;}
        
        Rational operator+(Rational rational);
        friend ostream &operator<<(ostream &stream,Rational &rational);
};

Rational Rational::operator+(Rational rational) {
    Rational result;
    result.numerator = this->numerator * rational.denominator + this->denominator * rational.numerator;
    result.denominator = this->denominator * rational.denominator;
    return result;
}
ostream &operator<<(ostream &stream,Rational &rational) {
    stream << rational.numerator << "/" << rational.denominator;
    return stream;
}

int main() {
    Rational r1(3, 4), r2(2, 5), r3;
    r3 = r1 + r2;
    cout << "Sum of " << r1 << " and " << r2 << " is " << r3 << endl;
    return 0;
} 
