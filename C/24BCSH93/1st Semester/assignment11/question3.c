#include <stdio.h>

struct student {
	char name[30];
	int roll_no;
	float marks;
};

int main() {
	struct student s1, s2;
	printf("Enter the name, roll no. and marks of the student: ");
	scanf("%s%d%f", s1.name, &s1.roll_no, &s1.marks);
	printf("Enter the name, roll no. and marks of the student: ");
	scanf("%s%d%f", s2.name, &s2.roll_no, &s2.marks);
	printf("Name\tRoll no.\tMarks\n");
	printf("%s\t%d\t\t%f\n", s1.name, s1.roll_no, s1.marks);
	printf("%s\t%d\t\t%f\n", s2.name, s2.roll_no, s2.marks);
	return 0;
}