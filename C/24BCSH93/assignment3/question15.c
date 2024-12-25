#include <stdio.h>

int main() {
	int dd1, mm1, yyyy1, dd2, mm2, yyyy2, dd, mm, yyyy;
	printf("Enter the DOB: ");
	scanf("%d%d%d", &dd1, &mm1, &yyyy1);
	printf("Enter current date: ");
	scanf("%d%d%d", &dd2, &mm2, &yyyy2);

	dd = dd2 - dd1;
	if (dd2 < dd1) {
		dd += 30;
		mm2--;
	}

	mm = mm2 - mm1;
	if (mm2 < mm1) {
		mm += 12;
		yyyy2--;
	}

	yyyy = yyyy2 - yyyy1;
	printf("Age %d years %d months and %d days\n", yyyy, mm, dd);
	return 0;
}
