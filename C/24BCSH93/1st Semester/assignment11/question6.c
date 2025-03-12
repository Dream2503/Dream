#include <stdio.h>

struct student {
	char name[30];
	int roll_no;
	char branch[3];
	float cgpa;
};

int main() {
	struct student stds[5];
	int i, max = 0;

	for (i = 0; i < 5; i++) {
		printf("Enter the name, roll no., branch and cgpa of student%d: ", i+1);
		scanf("%s%d%s%f", stds[i].name, &stds[i].roll_no, stds[i].branch, &stds[i].cgpa);
	}
	for (i = 1; i < 5; i++) {
		if (stds[max].cgpa < stds[i].cgpa) {
			max = i;
		}
	}
	printf("\nHighest cgpa amongst all the students is\n");
	printf("Name: %s\nRoll no.: %d\nBranch: %s\nCGPA: %f\n", stds[max].name, stds[max].roll_no, stds[max].branch, stds[max].cgpa);
	return 0;
}