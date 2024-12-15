#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    char name[10];
    float age;
    int id;
} Employee;

Employee* allocateEmployee(int length) {
    Employee *array = (Employee*)calloc(length, sizeof(Employee));
    for (int i = 0; i < length; i++){
        printf("Enter the name of #%d Employee: ", i+1);
        scanf("%s", &array[i].name);
        printf("Enter the age of #%d Employee: ", i+1);
        scanf("%f", &array[i].age);
        printf("Enter the id of #%d Employee: ", i+1);
        scanf("%d", &array[i].id);
    }
    return array;
}
void allocateEmployeeByRef(Employee **array, int length) {
    *array = (Employee*)calloc(length, sizeof(Employee));
    for (int i = 0; i < length; i++){
        printf("Enter the name of #%d Employee: ", i+1);
        scanf("%s", &(*array)[i].name);
        printf("Enter the age of #%d Employee: ", i+1);
        scanf("%f", &(*array)[i].age);
        printf("Enter the id of #%d Employee: ", i+1);
        scanf("%d", &(*array)[i].id);
    }
}
void printEmployee(Employee *array, int length) {
    for (int i = 0; i < length; i++){
        printf("#%d Employee name is %s\n", i+1, array[i].name);
        printf("#%d Employee age is %.1f\n", i+1, array[i].age);
        printf("#%d Employee name is %d\n", i+1, array[i].id);
        printf("\n");
    }
}

int main() {
    int len = 2;
    Employee *lst;
    allocateEmployeeByRef(&lst, len);
    printEmployee(lst, len);
    return 0;
}