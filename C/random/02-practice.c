#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void hello(char[], int);
void mul_table(int);

int main()
{
    // circumference and area of the circle

    /*
    const float PI = 3.14159;
    float radius;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    printf("Circumference of the circle is %0.5f\nArea of the circle is %0.5f", 2 * PI * radius, PI * radius * radius);
    */

    // hypotenuse of a triangle

    /*
    #include <math.h>

    float base;
    float height;

    printf("\nEnter base of the triangle: ");
    scanf("%f", &base);
    printf("Enter height of the triangle: ");
    scanf("%f", &height);

    printf("Hypotenuse of the triangle is %0.2f\n", sqrt(pow(base, 2) + pow(height, 2)));
    */

    // if-else statement

    /*
    int age;
    printf("Enter your age: \n");
    scanf("%d", &age);
    printf("Your age is %d\n", age);
    
    if(age <= 0)
    {
        printf("LMAO, bro you need to born first");
    }

    else if(age > 100)
    {
        printf("Bro go die first and wait for your next life. BYE BYE");
    }

    else if(age >= 18)
    {
        printf("You are an Adult");
    }

    else
    {
        printf("You are a Minor");
    }
    */

    // if-else alternative -> switch by checking grades

    /*
    char grade;
    printf("Enter Your Grade: \n");
    scanf("%c", &grade);
    printf("Your Grade is %c\n", grade);

    switch(grade)
    {
        case 'A':
            printf("Damn grade A");
            break;
        
        case 'B':
            printf("Damn grade B");
            break;

        case 'C':
            printf("Damn grade C");
            break;

        case 'D':
            printf("Damn grade D");
            break;

        default:
            printf("WTF do you mean?");
    }
    */

    // Converting Celsius to Ferenheit

    /*
    #include <ctype.h>

    char unit;
    float temp;

    printf("Enter unit of temperature: \n");
    scanf("%c", &unit);
    temp = toupper(unit);

    switch(unit)
    {
        case 'C':
            printf("Enter temperature in Celsius: \n");
            scanf("%f", &temp);
            temp = (9/5 * temp) + 32;
            printf("Temperature in Farenheit is %.1f", temp);
            break;

        case 'F':
            printf("Enter temperature in Ferenheit: \n");
            scanf("%f", &temp);
            temp = (temp - 32) * 5/9;
            printf("Temperature in Celsius is %.1f", temp);
            break;

        default:
            printf("%c is not a valud unit");
    }
    */

    // Calculator Program

    /*
    int num1;
    char opr;
    int num2;
    int res;

    printf("Enter number1: ");
    scanf("%d", &num1);
    printf("Enter operator to perform: ");
    scanf(" %c", &opr);
    printf("Enter number2: ");
    scanf("%d", &num2);

    switch(opr)
    {
        case '+':
            res = num1 + num2;
            break;
        
        case '-':
            res = num1 - num2;
            break;

        case '*':
            res = num1 * num2;
            break;

        case '/':
            res = num1 / num2;
            break;
        
        default:
            printf("Invalid operator for calculation");
    }

    printf("Result - %d", res);
    */

    // functions

    /*
    void func(char parm1[], int parm2)
    {
        printf("calling func with %s and %d", parm1, parm2);
    }

    int age = 18;
    char name[] = "Dream";

    func(name, age);
    */
    
    // type of function [squaring a number]

    /*
    float square(float num)
    {
        return num * num;
    }

    float x = 10;
    printf("Squaring %.1f we get %.1f", x, square(x));
    */

    // terniary operator for if else

    /*
    int max(int x, int y)
    {
        return (x > y) ? x : y;
    }

    printf("max = %d", max(9, 6));
    */

    // function prototype

    /*
    char name[] = "Dream";
    int age = 18;

    void hello(char name[], int age)
    {
        printf("Hello, %s you are %d years old", name, age);
    }

    hello(name, age);
    */

    // while loop

    /*
    int i = 0;

    while(i <= 10)
    {
        printf("%d\n", i);
        i++;
    }
    */

    // do while loop

    /*
    int num = 0;
    int sum = 0;

    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        if(num > 0)
        {
            sum += num;
        }
    } while(num > 0);
    printf("sum = %d", sum);
    */

    // array

    /*
    int lst[] = {1, 2, 3, 4, 5};
    int len = sizeof(lst) / sizeof(lst[0]);

    printf("{");
    for(int i = 0; i < len; i++)
    {
        printf("%d", lst[i]);

        if(i < len -1)
        {
            printf(", ");
        }
    }
    printf("}");
    */

    // struct [class without methods]

    /*
    struct Player
    {
        char name[10];
        int score;
    };
    
    struct Player player1;
    struct Player player2;
    strcpy(player1.name, "Dream");
    player1.score = 10;
    strcpy(player2.name, "Dew");
    player2.score = 20;

    printf("%s %d %s %d", player1.name, player1.score, player2.name, player2.score);
    */

    // enum

    /*
    enum Day{Sun, Mon, Tue, Wed, Thu, Fri, Sat};
    enum Day today = Mon;

    if(today == Sun || today == Sat)
    {
        printf("Holiday");
    }
    else
    {
        printf("Work");
    }
    */          

    return 0;
}
