#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[30];
    int roll;
    float cgpa;
} student;

student *maxCGPA(student *, int);

int main() {
    int size, i;
    printf("Enter total no. of students: ");
    scanf("%d", &size);
    student *stds = (student *) malloc(sizeof(student) * size);
    student *current, *res;

    for (i = 0; i < size; i++) {
        current = stds + i;
        printf("Enter name, roll, cgpa of student%d: ", i + 1);
        scanf("%s%d%f", current->name, &current->roll, &current->cgpa);
    }
    res = maxCGPA(stds, size);
    printf("Student with maximum CGPA is\n");
    printf("Name: %s\nRoll: %d\nCGPA: %.1f\n", res->name, res->roll, res->cgpa);
    free(stds);
    stds = NULL;
    return 0;
}

student *maxCGPA(student *stds, int size) {
    student *res = stds, *current;
    int i;

    for (i = 1; i < size; i++) {
        current = stds + i;

        if (res->cgpa < current->cgpa) {
            res = current;
        }
    }
    return res;
}
