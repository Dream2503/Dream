#include <stdio.h>
#include <stdbool.h>

int main() {
    char character = 'F';
    char string[] = "Dream";
    bool boolean = true;
    float decimal = 3.2;
    double adv_float = 3.14159;
    signed char signed_char = 120;
    unsigned char unsigned_char = 240;
    short int short_int = 30000;
    unsigned short int unsigned_short_int = 60000;
    int integer = 2000000000;
    unsigned int unsigned_integer = 4000000000;
    long long int long_integer_int = 9000000000000000000;
    unsigned long long int unsigned_long_int = 1800000000000000000U;

    printf("char [1 character string] - %c\n", character);
    printf("char array [multi character string] - %s\n", string);
    printf("bool - %d\n", boolean);
    printf("float [precision 6-7 digit] - %f\n", decimal);
    printf("double [precision 15-16] - %ld", adv_float);
    printf("signed char as integer [limit -128 to 127] - %d\n", signed_char);
    printf("signed char as char [same as above] - %c\n", signed_char);
    printf("unsigned char as integer [limit 0 to 255] - %d\n", unsigned_char);
    printf("unsigned char as char [same as above] - %c\n", unsigned_char);
    printf("short int [limit -32,768 to 32,767] - %d\n", short_int);
    printf("unsigned short int [limit 0 to 65,535] - %d\n", unsigned_short_int);
    printf("int [limit -2,147,483,648 to 2,147,483,647] - %d\n", integer);
    printf("unsigned int [limit 0 to 4,294,967,295] - %u\n", unsigned_integer);
    printf("long long int [limit -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807] - %lld\n", long_integer_int);
    printf("unsigned long long int [limit 0 to 18,446,744,073,709,551,615] - %lld\n", unsigned_long_int);

    return 0;
}
