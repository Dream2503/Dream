//  Q1. Implementation of Banker's Algorithm for Deadlock Detection.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int allocated, max, need;
} Resource;

int* safe_sequence(Resource**, int, int, int*);
bool request(Resource**, int, int, int*, int*);
void print_table(Resource**, int, int);

int main() {
    int i, j, process_size, resource_size, choice, *sequence, pid, *requests;
    printf("Enter the total no. of processes: ");
    scanf("%d", &process_size);
    printf("Enter the total no. of resources: ");
    scanf("%d", &resource_size);
    Resource** resources = (Resource**)malloc(process_size * sizeof(Resource*));

    if (!resources) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < process_size; i++) {
        resources[i] = (Resource*)malloc(resource_size * sizeof(Resource));

        if (!resources[i]) {
            printf("Memory was not allocated\n");
            exit(0);
        }
    }
    printf("\nEnter the allocation matrix:\n");

    for (i = 0; i < process_size; i++) {
        for (j = 0; j < resource_size; j++) {
            scanf("%d", &resources[i][j].allocated);
        }
    }
    printf("\nEnter the maximum matrix:\n");

    for (i = 0; i < process_size; i++) {
        for (j = 0; j < resource_size; j++) {
            scanf("%d", &resources[i][j].max);
            resources[i][j].need = resources[i][j].max - resources[i][j].allocated;

            if (resources[i][j].need < 0) {
                printf("Failed to allocate resources more than maximum need\n");

                for (i = 0; i < process_size; i++) {
                    free(resources[i]);
                }
                free(resources);
                exit(0);
            }
        }
    }
    int* available = (int*)malloc(resource_size * sizeof(int));

    if (!available) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    printf("\nEnter the available resources: ");

    for (j = 0; j < resource_size; j++) {
        scanf("%d", &available[j]);
    }
    while (true) {
        printf("\n-------------- MENU --------------\n");
        printf("1. Find Safe Sequence\n");
        printf("2. Request Resources\n");
        printf("3. Print Table\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            sequence = safe_sequence(resources, process_size, resource_size, available);

            if (sequence) {
                printf("Safe Sequence: ");

                for (i = 0; i < process_size; i++) {
                    printf("P%d ", sequence[i]);
                }
                printf("\n");
                free(sequence);
            } else {
                printf("No safe sequence, system is UNSAFE!\n");
            }
            break;

        case 2:
            requests = (int*)malloc(resource_size * sizeof(int));

            if (!requests) {
                printf("Memory was not allocated\n");
                exit(0);
            }
            printf("Enter process ID to request resources: ");
            scanf("%d", &pid);
            printf("Enter request vector (%d resources): ", resource_size);

            for (i = 0; i < resource_size; i++) {
                scanf("%d", &requests[i]);
            }
            if (request(resources, process_size, resource_size, available, requests)) {
                printf("Request GRANTED. System remains safe.\n");
            } else {
                printf("Request DENIED. System would become unsafe.\n");
            }
            free(requests);
            break;

        case 3:
            print_table(resources, process_size, resource_size);
            break;

        case 4:
            printf("Thank you for using the Program...\n");

            for (i = 0; i < process_size; i++) {
                free(resources[i]);
            }
            free(resources);
            free(available);
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

int* safe_sequence(Resource** resources, int process_size, int resource_size, int* available) {
    bool update = true, safe;
    int i, j, k = 0;
    bool* completed = (bool*)malloc(process_size * sizeof(bool));
    int* sequence = (int*)malloc(process_size * sizeof(int));

    for (i = 0; i < process_size; i++) {
        completed[i] = false;
    }
    while (update) {
        update = false;

        for (i = 0; i < process_size; i++) {
            if (!completed[i]) {
                safe = true;

                for (j = 0; j < resource_size; j++) {
                    if (resources[i][j].need + resources[i][j].allocated > resources[i][j].max || resources[i][j].need > available[j]) {
                        safe = false;
                        break;
                    }
                }
                if (safe) {
                    for (j = 0; j < resource_size; j++) {
                        available[j] += resources[i][j].allocated;
                    }
                    sequence[k++] = i;
                    completed[i] = true;
                    update = true;
                }
            }
        }
    }
    safe = true;

    for (i = 0; i < process_size; i++) {
        if (!completed[i]) {
            safe = false;
            free(sequence);
            sequence = NULL;
            break;
        }
    }
    free(completed);
    return sequence;
}

bool request(Resource** resources, int process_size, int resource_size, int* available, int* request) {
    bool grant;
    int i;
    Resource** resources_copy = (Resource**)malloc(process_size * sizeof(Resource*));
    int* available_copy = (int*)malloc(resource_size * sizeof(int));

    if (!resources_copy || !available_copy) {
        printf("Memory was not allocated");
        exit(0);
    }
    memcpy(available_copy, available, resource_size * sizeof(int));

    for (i = 0; i < process_size; i++) {
        resources_copy[i] = (Resource*)malloc(resource_size * sizeof(Resource));

        if (!resources[i]) {
            printf("Memory was not allocated");
            exit(0);
        }
        memcpy(resources_copy[i], resources[i], resource_size * sizeof(Resource));
    }
    int* sequence = safe_sequence(resources_copy, process_size, resource_size, available_copy);

    if (sequence) {
        free(sequence);
        grant = true;
    } else {
        grant = false;
        memcpy(available, available_copy, resource_size * sizeof(int));

        for (i = 0; i < process_size; i++) {
            memcpy(resources[i], resources_copy[i], resource_size * sizeof(Resource));
        }
    }
    for (i = 0; i < process_size; i++) {
        free(resources_copy[i]);
    }
    free(resources_copy);
    free(available_copy);
    return grant;
}

void print_table(Resource** resources, int process_size, int resource_size) {
    int i, j;
    printf("\n\tAllocation\t\tMax\t\t\tNeed\n");
    printf("\t");

    for (j = 0; j < resource_size; j++) {
        printf("R%d ", j);
    }
    printf("\t\t");

    for (j = 0; j < resource_size; j++) {
        printf("R%d ", j);
    }
    printf("\t\t");

    for (j = 0; j < resource_size; j++) {
        printf("R%d ", j);
    }
    printf("\n");

    for (i = 0; i < process_size; i++) {
        printf("P%d\t", i);

        for (j = 0; j < resource_size; j++) {
            printf("%2d ", resources[i][j].allocated);
        }
        printf("\t\t");

        for (j = 0; j < resource_size; j++) {
            printf("%2d ", resources[i][j].max);
        }
        printf("\t\t");

        for (j = 0; j < resource_size; j++) {
            printf("%2d ", resources[i][j].need);
        }
        printf("\n");
    }
}
