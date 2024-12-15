#include <stdio.h>

typedef struct rational {int numerator, denominator;} Rational;

Rational inputRational() {
    Rational number;
    printf("Enter the numerator: ");
    scanf("%d", &number.numerator);
    printf("Enter the denominator ");
    scanf("%d", &number.denominator);
    return number;
}

Rational addRational(Rational num1, Rational num2) {
    Rational result;

    if (num1.denominator == num2.denominator) {
        result.numerator = num1.numerator + num2.numerator;
        result.denominator = num1.denominator;
    } else {
        result.numerator = (num2.denominator * num1.numerator) + (num1.denominator * num2.numerator);
        result.denominator = num1.denominator * num2.denominator;
    }
    return result;
}

Rational subRational(Rational num1, Rational num2) {
    Rational result;

    if (num1.denominator == num2.denominator) {
        result.numerator = num1.numerator - num2.numerator;
        result.denominator = num1.denominator;
    } else {
        result.numerator = (num2.denominator * num1.numerator) - (num1.denominator * num2.numerator);
        result.denominator = num1.denominator * num2.denominator;
    }
    return result;
}

Rational mulRational(Rational num1, Rational num2) {
    Rational result;
    result.numerator = num1.numerator * num2.numerator;
    result.denominator = num1.denominator * num2.denominator;
    return result;
}

Rational divRational(Rational num1, Rational num2) {
    Rational result;
    result.numerator = num1.numerator * num2.denominator;
    result.denominator = num1.denominator * num2.numerator;
    return result;
}

int isSmallerRational(Rational num1, Rational num2) {
    if (num1.denominator == num2.denominator) {
        if (num1.numerator < num2.denominator)
            return 1;
        else
            return 0;
    } else {
        if ((num2.denominator * num1.numerator) < (num1.denominator * num2.numerator))
            return 1;
        else
            return 0;
    }
}

int isEqualRational(Rational num1, Rational num2) {
    if (num1.denominator == num2.denominator) {
        if (num1.numerator = num2.denominator)
            return 1;
        else
            return 0;
    } else {
        if ((num2.denominator * num1.numerator) == (num1.denominator * num2.numerator))
            return 1;
        else
            return 0;
    }
}

void printRational(Rational number) {printf("Rational(%d/%d)\n", number.numerator, number.denominator);}
void incrementRational(Rational *number) {(*number).numerator += (*number).denominator;}
void decrementRational(Rational *number) {(*number).numerator -= (*number).denominator;}
int isBiggerRational(Rational num1, Rational num2) {return !isSmallerRational(num1, num2);}
int isNotEqualRational(Rational num1, Rational num2) {return !isEqualRational(num1, num2);}

int main() {
    Rational rat1 = inputRational();
    Rational rat2 = inputRational();
    printRational(rat1);
    printRational(rat2);
    printRational(addRational(rat1, rat2));
    printRational(subRational(rat1, rat2));
    printRational(mulRational(rat1, rat2));
    printRational(divRational(rat1, rat2));
    incrementRational(&rat1);
    decrementRational(&rat2);
    printRational(rat1);
    printRational(rat2);
    return 0;
}