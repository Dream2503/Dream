#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
    int pid, priority;
    float arrival, departure;
    float burst, remaining;
    float waiting, turnaround, response;
} Process;

typedef struct {
    int pid;
    float end;
} GanttChartElement;

typedef struct {
    GanttChartElement* chart;
    int size;
} GanttChart;

typedef struct {
    Process** heap;
    int size;
    int (*comparator)(const void*, const void*);
} PriorityQueue;

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

int parent(int i) {
    if (i % 2 == 0) {
        return i / 2 - 1;
    }
    return i / 2;
}

void push(PriorityQueue* queue, Process* process) {
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

void pop(PriorityQueue* queue) {
    queue->heap[0] = queue->heap[--queue->size];
    min_heapify(queue, 0);
}

void display_process_table(char name[], Process* processes, int size) {
    int i;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;
    printf("\n\t\t\t%s\n", name);
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tResponse Time\n");

    for (i = 0; i < size; i++) {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].waiting,
               processes[i].turnaround, processes[i].response);
        total_waiting += processes[i].waiting;
        total_turnaround += processes[i].turnaround;
        total_response += processes[i].response;
    }
    printf("\nAverage Waiting time:\t\t%.2f\n", total_waiting / size);
    printf("Average Turn-Around time:\t%.2f\n", total_turnaround / size);
    printf("Average Response Time:\t\t%.2f\n\n", total_response / size);
}

void display_gantt_chart(GanttChart gantt_chart) {
    int i;
    printf("Gantt Chart: 0.00");

    for (i = 0; i < gantt_chart.size; i++) {
        if (gantt_chart.chart[i].pid == -1) {
            printf(" <- IDEAL -> %.2f", gantt_chart.chart[i].end);
        } else {
            printf(" <- P%d -> %.2f", gantt_chart.chart[i].pid, gantt_chart.chart[i].end);
        }
    }
    printf("\n");
}

GanttChart FCFS(Process* processes, int size, float time_slice) {
    int i = 0;
    float time = 0;
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 2 * sizeof(GanttChartElement)), 0};

    if (!gantt_chart.chart) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    qsort(processes, size, sizeof(Process), arrival_comparator);

    for (i = 0; i < size; i++) {
        if (time < processes[i].arrival) {
            time = processes[i].arrival;
            gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){-1, time};
        }
        processes[i].response = processes[i].waiting = time - processes[i].arrival;
        time += processes[i].burst;
        processes[i].turnaround = time - processes[i].arrival;
        gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){processes[i].pid, time};
    }
    return gantt_chart;
}

GanttChart SRTF(Process* processes, int size, bool preemptive) {
    int i = 0;
    float time = 0;
    Process* process;
    PriorityQueue queue = {(Process**)malloc(size * sizeof(Process*)), 0, remaining_comparator};
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 4 * sizeof(GanttChartElement)), 0};

    if (!queue.heap || !gantt_chart.chart) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    qsort(processes, size, sizeof(Process), arrival_comparator);

    while (queue.size || i < size) {
        if (!queue.size && i < size && time < processes[i].arrival) {
            time = processes[i].arrival;
            gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){-1, time};
        }
        while (i < size && processes[i].arrival <= time) {
            processes[i].remaining = processes[i].burst;
            push(&queue, &processes[i++]);
        }
        if (queue.size) {
            process = queue.heap[0];
            pop(&queue);

            if (process->remaining == process->burst) {
                process->response = time - process->arrival;
            }
            if (preemptive && i < size && processes[i].arrival < time + process->remaining && processes[i].burst < process->remaining) {
                process->remaining -= processes[i].arrival - time;
                time = processes[i].arrival;
                gantt_chart.chart[gantt_chart.size++] = (GanttChartElement){process->pid, time};
                push(&queue, process);
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

GanttChart PRIORITY(Process* processes, int size, bool preemptive) {
    int i = 0;
    float time = 0;
    Process* process;
    PriorityQueue queue = {(Process**)malloc(size * sizeof(Process*)), 0, priority_comparator};
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 4 * sizeof(GanttChartElement)), 0};
    free(queue.heap);
    return gantt_chart;
}

int main() {
    int size, i;
    GanttChart gantt_chart;
    printf("Enter the number of processes: ");
    scanf("%d", &size);
    Process* processes = (Process*)malloc(size * sizeof(Process));

    if (!processes) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < size; i++) {
        printf("Enter the PID, Arrival, Burst time and Priority of %dth process: ", i + 1);
        scanf("%d%f%f%d", &processes[i].pid, &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }
    gantt_chart = FCFS(processes, size, INFINITY);
    display_process_table("FIRST-COME-FIRST-SERVE ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    gantt_chart = SRTF(processes, size, false);
    display_process_table("SHORTEST-JOB-FIRST ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    gantt_chart = SRTF(processes, size, true);
    display_process_table("SHORTEST-REMAINING-TIME-FIRST ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    gantt_chart = PRIORITY(processes, size, false);
    display_process_table("NON-PREEMPTIVE-PRIORITY ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    gantt_chart = PRIORITY(processes, size, true);
    display_process_table("PREEMPTIVE-PRIORITY ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    float time_slice = 2;
    gantt_chart = FCFS(processes, size, time_slice);
    display_process_table("ROUND-ROBIN ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    free(processes);
    return 0;
}
