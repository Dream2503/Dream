#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade; // Declaration
    
    printf("Enter your grade: ");
    scanf("%d", &grade); // Getting input from user
    
    if(grade>80) // If grade is above 80
        printf("Excellent Job!\n");
    else if(grade>60) // If grade is not above 80 but still above 60
        printf("Not bad...Study more next time.\n");
    else // If grade is less than 60 (or equals to 60)
        printf("Oh.. You didn't pass..\n");
        
    return 0;
}
