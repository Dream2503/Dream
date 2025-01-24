#include <stdio.h>

struct student {
	char name[20];
	int roll;
	float marks;
	struct DOB {
		int dd, mm, yyyy;
	} dob;
};

int main() {
	struct student s1;
	printf("Enter the name, roll, marks and DOB of the student: ");
	scanf("%s%d%f%d%d%d", s1.name, &s1.roll, &s1.marks, &s1.dob.dd, &s1.dob.mm, &s1.dob.yyyy);
	printf("Details of the student is:\n");
	printf("Name: %s\nRoll no.: %d\nMarks: %f\nDOB: %d/%d/%d\n", s1.name, s1.roll, s1.marks, s1.dob.dd, s1.dob.mm, s1.dob.yyyy);
	return 0;
}