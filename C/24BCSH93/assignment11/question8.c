#include <stdio.h>

typedef struct TIME {
	int hour, min, sec;
} TIME;

TIME ADDTIME(TIME, TIME);

int main() {
	TIME t1, t2, res;
	printf("Enter the hour, min and sec for time 1: ");
	scanf("%d%d%d", &t1.hour, &t1.min, &t1.sec);
	printf("Enter the hour, min and sec for time 2: ");
	scanf("%d%d%d", &t2.hour, &t2.min, &t2.sec);
	res = ADDTIME(t1, t2);
	printf("Result of addition of both time is %d hours %d minutes %d seconds\n", res.hour, res.min, res.sec);
	return 0;
}

TIME ADDTIME(TIME t1, TIME t2) {
	TIME res;
	res.sec = t1.sec + t2.sec;
	res.min = t1.min + t2.min;
	res.hour = t1.hour + t2.hour;

	if (res.sec >= 60) {
		res.min += res.sec / 60;
		res.sec %= 60;
	} if (res.min >= 60) {
		res.hour += res.min / 60;
		res.min %= 60;
	}
	return res;
}