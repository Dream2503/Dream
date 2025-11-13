/*
Title: Implementation and Comparison of CPU Scheduling Algorithms

Objective: To simulate and analyze various CPU scheduling algorithms in terms of average waiting time, turnaround time, and Response Time.

Problem Statement:
Write a program to implement the following CPU Scheduling Algorithms:
    1. First-Come, First-Served (FCFS) Scheduling
    2. Shortest Job First (SJF) Scheduling – Non-preemptive
    3. Shortest Remaining Time First (SRTF) Scheduling – Preemptive
    4. Priority Scheduling (both Non-preemptive and Preemptive)
    5. Round Robin (RR) Scheduling with a given Time Quantum

Input Requirements:
    • Number of processes (n)
    • For each process:
        o Process ID
        o Arrival Time
        o Burst Time
        o Priority (for Priority Scheduling)
    • Time Quantum (for RR Scheduling)

Output Requirements:
For each algorithm, display:
    • Gantt Chart (sequence of process execution)
    • Waiting Time and Turnaround Time for each process
    • Average Waiting Time and Average Turnaround Time

Tasks to be Performed:
    1. Implement each scheduling algorithm as a separate function or module.
    2. Display and compare the average waiting and turnaround times for all algorithms.
    3. Analyze and comment on which algorithm performs best for different types of input cases
       (e.g., short jobs, long jobs, varying priorities, etc.)

Optional Extension (for bonus marks):
Implement all algorithms in a single menu-driven program where the user can choose the scheduling algorithm.
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, priority;
    float arrival, departure, burst, remaining, waiting, turnaround, response;
} Process;

typedef struct {
    int pid;
    float finish;
} GanttChartElement;

typedef struct {
    GanttChartElement* chart;
    int size;
} GanttChart;

typedef struct Node {
    Process* data;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

typedef struct {
    Process** heap;
    int size, (*comparator)(const void*, const void*);
} PriorityQueue;

int arrival_comparator(const void*, const void*);
int remaining_comparator(const void*, const void*);
int priority_comparator(const void*, const void*);
void queue_push(Queue*, Process*);
void queue_pop(Queue*);
int parent(int);
void min_heapify(PriorityQueue*, int);
void heap_push(PriorityQueue*, Process*);
void heap_pop(PriorityQueue*);
GanttChart scheduling_queue_impl(Process*, int, float);
GanttChart scheduling_heap_impl(Process*, int, bool, int (*)(const void*, const void*));
void display_process_table(char[], const Process*, int);
void display_gantt_chart(GanttChart);

GanttChart FCFS(Process* processes, int size) { return scheduling_queue_impl(processes, size, INFINITY); }
GanttChart SJF(Process* processes, int size) { return scheduling_heap_impl(processes, size, false, remaining_comparator); }
GanttChart SRTF(Process* processes, int size) { return scheduling_heap_impl(processes, size, true, remaining_comparator); }
GanttChart non_preemptive_priority(Process* processes, int size) { return scheduling_heap_impl(processes, size, false, priority_comparator); }
GanttChart preemptive_priority(Process* processes, int size) { return scheduling_heap_impl(processes, size, true, priority_comparator); }
GanttChart round_robin(Process* processes, int size, float time_slice) { return scheduling_queue_impl(processes, size, time_slice); }

int main() {
    char choice;
    int size, i;
    float time_slice;
    GanttChart gantt_chart;
    printf("Enter the number of processes: ");
    scanf("%d", &size);
    Process* processes = (Process*)malloc(size * sizeof(Process));

    if (!processes) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    printf("\nEnter Process details:\n");

    for (i = 0; i < size; i++) {
        printf("Enter PID, Arrival Time, Burst Time, Priority for process %d: ", i + 1);
        scanf("%d%f%f%d", &processes[i].pid, &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }
    while (true) {
        printf("\n==================== CPU SCHEDULING ALGORITHMS ====================\n");
        printf("1. First-Come, First-Served (FCFS)\n");
        printf("2. Shortest Job First (SJF) - Non-Preemptive\n");
        printf("3. Shortest Remaining Time First (SRTF) - Preemptive\n");
        printf("4. Priority Scheduling - Non-Preemptive\n");
        printf("5. Priority Scheduling - Preemptive\n");
        printf("6. Round Robin (RR)\n");
        printf("0. Exit\n");
        printf("===================================================================\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '0':
            printf("\nThank you for using the Program!\n");
            free(processes);
            return 0;

        case '1':
            gantt_chart = FCFS(processes, size);
            display_process_table("FIRST-COME-FIRST-SERVED (FCFS)", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        case '2':
            gantt_chart = SJF(processes, size);
            display_process_table("SHORTEST JOB FIRST (SJF) - NON PREEMPTIVE", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        case '3':
            gantt_chart = SRTF(processes, size);
            display_process_table("SHORTEST REMAINING TIME FIRST (SRTF) - PREEMPTIVE", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        case '4':
            gantt_chart = non_preemptive_priority(processes, size);
            display_process_table("PRIORITY SCHEDULING - NON PREEMPTIVE", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        case '5':
            gantt_chart = preemptive_priority(processes, size);
            display_process_table("PRIORITY SCHEDULING - PREEMPTIVE", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        case '6':
            printf("Enter Time Quantum for Round Robin: ");
            scanf("%f", &time_slice);
            gantt_chart = round_robin(processes, size, time_slice);
            display_process_table("ROUND ROBIN (RR)", processes, size);
            display_gantt_chart(gantt_chart);
            free(gantt_chart.chart);
            break;

        default:
            printf("Invalid choice! Please enter a valid option (0–6).\n");
            break;
        }
    }
}

int arrival_comparator(const void* a, const void* b) {
    Process *lhs = (Process*)a, *rhs = (Process*)b;

    if (lhs->arrival < rhs->arrival) {
        return -1;
    }
    if (lhs->arrival > rhs->arrival) {
        return 1;
    }
    return 0;
}

int remaining_comparator(const void* a, const void* b) {
    Process *lhs = (Process*)a, *rhs = (Process*)b;

    if (lhs->remaining < rhs->remaining) {
        return -1;
    }
    if (lhs->remaining > rhs->remaining) {
        return 1;
    }
    return 0;
}

int priority_comparator(const void* a, const void* b) {
    Process *lhs = (Process*)a, *rhs = (Process*)b;

    if (lhs->priority < rhs->priority) {
        return -1;
    }
    if (lhs->priority > rhs->priority) {
        return 1;
    }
    return 0;
}

void queue_push(Queue* queue, Process* process) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node) {
        printf("Memory was not allocated");
        exit(0);
    }
    node->data = process;
    node->next = NULL;

    if (queue->rear) {
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
}

void queue_pop(Queue* queue) {
    if (queue->front) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    if (!queue->front) {
        queue->rear = NULL;
    }
}

int parent(int i) {
    if (i % 2 == 0) {
        return i / 2 - 1;
    }
    return i / 2;
}

void min_heapify(PriorityQueue* queue, int i) {
    int left = i * 2 + 1, right = left + 1, min = i;

    if (left < queue->size &&
        (queue->comparator(queue->heap[left], queue->heap[min]) < 0 ||
         queue->comparator(queue->heap[left], queue->heap[min]) == 0 && arrival_comparator(queue->heap[left], queue->heap[min]) < 0)) {
        min = left;
    }
    if (right < queue->size &&
        (queue->comparator(queue->heap[right], queue->heap[min]) < 0 ||
         queue->comparator(queue->heap[right], queue->heap[min]) == 0 && arrival_comparator(queue->heap[right], queue->heap[min]) < 0)) {
        min = right;
    }
    if (min != i) {
        Process* temp = queue->heap[i];
        queue->heap[i] = queue->heap[min];
        queue->heap[min] = temp;

        if (min < queue->size / 2) {
            min_heapify(queue, min);
        }
    }
}

void heap_push(PriorityQueue* queue, Process* process) {
    int i = queue->size++;
    queue->heap[i] = process;

    while (i > 0 &&
           (queue->comparator(queue->heap[i], queue->heap[parent(i)]) < 0 ||
            queue->comparator(queue->heap[i], queue->heap[parent(i)]) == 0 && arrival_comparator(queue->heap[i], queue->heap[parent(i)]) < 0)) {
        Process* temp = queue->heap[i];
        queue->heap[i] = queue->heap[parent(i)];
        queue->heap[parent(i)] = temp;
        i = parent(i);
    }
}

void heap_pop(PriorityQueue* queue) {
    queue->heap[0] = queue->heap[--queue->size];
    min_heapify(queue, 0);
}

GanttChart scheduling_queue_impl(Process* processes, int size, float time_slice) {
    int i;
    float time = 0;
    Process* process;
    Queue queue = {NULL, NULL};
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 4 * sizeof(GanttChartElement)), 0};

    if (!gantt_chart.chart) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < size; i++) {
        processes[i].remaining = processes[i].burst;
    }
    i = 0;
    qsort(processes, size, sizeof(Process), arrival_comparator);

    while (queue.front || i < size) {
        if (!queue.front && i < size && time < processes[i].arrival) {
            time = processes[i].arrival;
            gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){-1, time};
        }
        while (i < size && processes[i].arrival <= time) {
            queue_push(&queue, &processes[i++]);
        }
        if (queue.front) {
            process = queue.front->data;
            queue_pop(&queue);

            if (process->remaining == process->burst) {
                process->response = time - process->arrival;
            }
            if (time_slice < process->remaining) {
                process->remaining -= time_slice;
                time += time_slice;
                gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){process->pid, time};

                while (i < size && processes[i].arrival <= time) {
                    queue_push(&queue, &processes[i++]);
                }
                queue_push(&queue, process);
            } else {
                time += process->remaining;
                process->remaining = 0;
                process->departure = time;
                gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){process->pid, time};
            }
        }
    }
    for (i = 0; i < size; i++) {
        processes[i].turnaround = processes[i].departure - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
    }
    return gantt_chart;
}

GanttChart scheduling_heap_impl(Process* processes, int size, bool preemptive, int (*comparator)(const void*, const void*)) {
    int i;
    float time = 0;
    Process* process;
    PriorityQueue queue = {(Process**)malloc(size * sizeof(Process*)), 0, comparator};
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 4 * sizeof(GanttChartElement)), 0};

    if (!queue.heap || !gantt_chart.chart) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    for (i = 0; i < size; i++) {
        processes[i].remaining = processes[i].burst;
    }
    i = 0;
    qsort(processes, size, sizeof(Process), arrival_comparator);

    while (queue.size || i < size) {
        if (!queue.size && i < size && time < processes[i].arrival) {
            time = processes[i].arrival;
            gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){-1, time};
        }
        while (i < size && processes[i].arrival <= time) {
            heap_push(&queue, &processes[i++]);
        }
        if (queue.size) {
            process = queue.heap[0];
            heap_pop(&queue);

            if (process->remaining == process->burst) {
                process->response = time - process->arrival;
            }
            if (preemptive && i < size && processes[i].arrival < time + process->remaining && comparator(&processes[i], process) < 0) {
                process->remaining -= processes[i].arrival - time;
                time = processes[i].arrival;
                gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){process->pid, time};

                while (i < size && processes[i].arrival <= time) {
                    heap_push(&queue, &processes[i++]);
                }
                heap_push(&queue, process);
            } else {
                time += process->remaining;
                process->remaining = 0;
                process->departure = time;
                gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){process->pid, time};
            }
        }
    }
    for (i = 0; i < size; i++) {
        processes[i].turnaround = processes[i].departure - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
    }
    free(queue.heap);
    return gantt_chart;
}

void display_process_table(char name[], const Process* processes, int size) {
    int i;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;
    printf("\n========================================================================================================\n");
    printf("\t\t\t\t\t%s\n", name);
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-13s | %-11s | %-9s | %-13s | %-17s | %-14s |\n", "PID", "Arrival Time", "Burst Time", "Priority", "Waiting Time",
           "Turnaround Time", "Response Time");
    printf("--------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < size; i++) {
        printf("| %-5d | %-13.2f | %-11.2f | %-9d | %-13.2f | %-17.2f | %-14.2f |\n", processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].priority, processes[i].waiting, processes[i].turnaround, processes[i].response);
        total_waiting += processes[i].waiting;
        total_turnaround += processes[i].turnaround;
        total_response += processes[i].response;
    }
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Average Waiting Time    : %.2f\n", total_waiting / size);
    printf("Average Turnaround Time : %.2f\n", total_turnaround / size);
    printf("Average Response Time   : %.2f\n", total_response / size);
    printf("========================================================================================================\n\n");
}

void display_gantt_chart(GanttChart gantt_chart) {
    int i;
    printf("Gantt Chart:\n");

    for (i = 0; i < gantt_chart.size; i++) {
        printf("-----------");
    }
    printf("-\n|");

    for (i = 0; i < gantt_chart.size; i++) {
        if (gantt_chart.chart[i].pid == -1) {
            printf("   IDLE   |");
        } else {
            printf("   P%-3d   |", gantt_chart.chart[i].pid);
        }
    }
    printf("\n");

    for (i = 0; i < gantt_chart.size; i++) {
        printf("-----------");
    }
    printf("-\n0.00");

    for (i = 0; i < gantt_chart.size; i++) {
        if (gantt_chart.chart[i].finish < 10) {
            printf("       %.2f", gantt_chart.chart[i].finish);
        } else if (gantt_chart.chart[i].finish < 100) {
            printf("      %.2f", gantt_chart.chart[i].finish);
        } else {
            printf("     %.2f", gantt_chart.chart[i].finish);
        }
    }
    printf("\n\n");
}
