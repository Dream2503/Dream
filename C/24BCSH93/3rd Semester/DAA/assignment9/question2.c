//  Q2. Implementation of Activity Selection Problem.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, start, finish;
} Activity;

int comparator(const void*, const void*);
int activity_selection(Activity*, int, Activity*);

int main() {
    int size, i;
    printf("Enter the total number of activities: ");
    scanf("%d", &size);
    Activity *activities = (Activity*)malloc(size * sizeof(Activity)), *selected = (Activity*)malloc(size * sizeof(Activity));

    if (!activities || !selected) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < size; i++) {
        printf("Enter the ID, starting time and finishing time of %dth activity: ", i + 1);
        scanf("%d%d", &activities[i].start, &activities[i].finish);
        activities[i].id = i + 1;
    }
    int selects = activity_selection(activities, size, selected);
    printf("\nAll the selected activities are:\n");

    for (i = 0; i < selects; i++) {
        printf("ID: %d\t", selected[i].id);
        printf("Starting Time: %d\t", selected[i].start);
        printf("Finishing Time: %d\n", selected[i].finish);
    }
    free(activities);
    free(selected);
}

int comparator(const void* a, const void* b) {
    Activity lhs = *(Activity*)a, rhs = *(Activity*)b;

    if (lhs.finish < rhs.finish) {
        return -1;
    }
    if (lhs.finish > rhs.finish) {
        return 1;
    }
    return 0;
}

int activity_selection(Activity* activities, int size, Activity* selected) {
    qsort(activities, size, sizeof(Activity), comparator);
    int i, k = 0;
    selected[0] = activities[0];

    for (i = 1; i < size; i++) {
        if (activities[i].start >= selected[k].finish) {
            selected[++k] = activities[i];
        }
    }
    return k + 1;
}