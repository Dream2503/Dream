//  Q1. Implementation of Fractional Knapsack Problem.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float profit, weight, percentage;
} Product;

int comparator(const void*, const void*);
float fractional_knapsack(Product*, int, float);

int main() {
    int size, i;
    float target;
    printf("Enter the total number of products: ");
    scanf("%d", &size);
    Product* sack = (Product*)malloc(size * sizeof(Product));

    if (!sack) {
        printf("Memory was not allocated\n");
        return 1;
    }
    for (i = 0; i < size; i++) {
        printf("Enter the ID, profit and weight of %dth product: ", i + 1);
        scanf("%d%f%f", &sack[i].id, &sack[i].profit, &sack[i].weight);
        sack[i].percentage = 0;
    }
    printf("Enter the targeted weight to achieve: ");
    scanf("%f", &target);
    float max = fractional_knapsack(sack, size, target);
    printf("\nThe ratio of products to take to maximize profit are:\n");

    for (i = 0; i < size; i++) {
        printf("ID: %d\t", sack[i].id);
        printf("Percentage: %.2f%%\n", sack[i].percentage);
    }
    printf("Maximum profit is: %.2f\n", max);
    free(sack);
    return 0;
}

int comparator(const void* a, const void* b) {
    Product lhs = *(Product*)a, rhs = *(Product*)b;
    float lhs_ratio = lhs.weight != 0 ? lhs.profit / lhs.weight : 0, rhs_ratio = rhs.weight != 0 ? rhs.profit / rhs.weight : 0;

    if (lhs_ratio < rhs_ratio) {
        return 1;
    }
    if (lhs_ratio > rhs_ratio) {
        return -1;
    }
    return 0;
}

float fractional_knapsack(Product* sack, int size, float target) {
    int i = 0;
    float res = 0;
    qsort(sack, size, sizeof(Product), comparator);

    while (i < size && sack[i].weight <= target) {
        target -= sack[i].weight;
        sack[i].percentage = 100;
        res += sack[i++].profit;
    }
    if (i < size && sack[i].weight > 0) {
        sack[i].percentage = target / sack[i].weight * 100;
        res += sack[i].profit * sack[i].percentage;
    }
    return res;
}
