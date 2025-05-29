#include <stdio.h>

struct employee {
    char name[30];
    int id;
    float salary;
};

int main() {
    struct employee emps[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter the name, id and salary of employee%d: ", i + 1);
        scanf("%s%d%f", emps[i].name, &emps[i].id, &emps[i].salary);
    }
    printf("\nDetails of the employees are: \n");
    printf("Sl no.\tName\tID\tSalary\n");

    for (i = 0; i < 5; i++) {
        printf("%d\t%s\t%d\t%f\n", i + 1, emps[i].name, emps[i].id, emps[i].salary);
    }
    return 0;
}
