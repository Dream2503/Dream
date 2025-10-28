#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	float profit, weight, ratio;
} Element;

int compartor(Element, Element);
int partition(Element*, int, int);
void quick_sort(Element*, int, int);
void fractional_knapsack(Element*, int, float);

int main() {
	int size, i;
	float target;
	printf("Enter the total number of elements available: ");
	scanf("%d", &size);
	Element *sack = (Element*)malloc(size * sizeof(Element));

	for (i = 0; i < size; i++) {
		printf("Enter the id, profit and weight of %dth element: ", i + 1);
		scanf("%d%f%f", &sack[i].id, &sack[i].profit, &sack[i].weight);
		sack[i].ratio = 0;
	}
	printf("Enter the targeted weight to acheive: ");
	scanf("%f", &target);
	fractional_knapsack(sack, size, target);
	printf("The ratio of elements to take to maximize profit are:\n");

	for (i = 0; i < size; i++) {
		printf("ID: %d\tRatio: %.2f\n", sack[i].id, sack[i].ratio);
	}
	return 0;
}

int comparator(Element lhs, Element rhs) {
	return lhs.profit / lhs.weight >= rhs.profit / rhs.weight;
}

void quick_sort(Element* sack, int low, int high) {
    if (low < high) {
        int mid = partition(sack, low, high);
        quick_sort(sack, low, mid - 1);
        quick_sort(sack, mid + 1, high);
    }
}

int partition(Element* sack, int low, int high) {
    int i = low + rand() % (high - low + 1), j;
	Element temp;
    temp = sack[i];
    sack[i] = sack[high];
    sack[high] = temp;
	Element pivot = sack[high];

    for (j = low; j <= high; j++) {
        if (comparator(sack[j], pivot)) {
            temp = sack[j];
            sack[j] = sack[i];
            sack[i++] = temp;
        }
    }
    return i - 1;
}

void fractional_knapsack(Element* sack, int size, float target) {
	int i = 0;
	quick_sort(sack, 0, size - 1);

	while (sack[i].weight <= target) {
		target -= sack[i].weight;
		sack[i].ratio = 1;
		i++;
	}
	if (i < size) {
		sack[i].ratio = target / sack[i].weight;
	}
}