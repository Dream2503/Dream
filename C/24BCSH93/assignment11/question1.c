#include <stdio.h>

struct student {
	char name[30];
	int roll_no;
	float marks;
};

int main() {
	struct student s1;
	printf("Enter the name, roll no. and marks of the student: ");
	scanf("%s%d%f", s1.name, &s1.roll_no, &s1.marks);
	printf("Details of the student are: \n");
	printf("Name: %s\nRoll no: %d\nMarks: %f\n", s1.name, s1.roll_no, s1.marks);
	return 0;
}