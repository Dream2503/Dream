#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	float profit, weight, ratio;
} Element;

int compartor(Element, Element);
void merge(Element*, Element*, int, int, int);
void merge_sort(Element*, Element*, int, int);
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

int compartor(Element lhs, Element rhs) {
	return lhs.profit / lhs.weight >= rhs.profit / rhs.weight;
}

void merge(Element* sack, Element* sorted, int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	
	while (i <= mid && j <= high) {
		if (compartor(sack[i], sack[j])) {
			sorted[k++] = sack[i++];
		} else {
			sorted[k++] = sack[j++];
		}
	}
	while (i <= mid) {
		sorted[k++] = sack[i++];
	}
	while (j <= high) {
		sorted[k++] = sack[j++];
	}
	for (k = low; k <= high; k++) {
		sack[k] = sorted[k];
	}
}

void merge_sort(Element* array, Element* sorted, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		merge_sort(array, sorted, low, mid);
		merge_sort(array, sorted, mid + 1, high);
		merge(array, sorted, low, mid, high);
	}
}

void fractional_knapsack(Element* sack, int size, float target) {
	int i = 0;
	Element* sorted = (Element*)malloc(size * sizeof(Element));
	merge_sort(sack, sorted, 0, size - 1);
	free(sorted);

	while (sack[i].weight <= target) {
		target -= sack[i].weight;
		sack[i].ratio = 1;
		i++;
	}
	if (i < size) {
		sack[i].ratio = target / sack[i].weight;
	}
}
