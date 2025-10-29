#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    float arrival, burst;
    float start, end, remaining;
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
} PriorityQueue;

void min_heapify(PriorityQueue* queue, int i) {
    int left = (i + 1) * 2 - 1, right = left + 1, min = i;

    if (left < queue->size &&
        (queue->heap[left]->remaining < queue->heap[min]->remaining ||
         (queue->heap[left]->remaining == queue->heap[min]->remaining && queue->heap[left]->arrival < queue->heap[min]->arrival))) {
        min = left;
    }
    if (right < queue->size &&
        (queue->heap[right]->remaining < queue->heap[min]->remaining ||
         (queue->heap[right]->remaining == queue->heap[min]->remaining && queue->heap[right]->arrival < queue->heap[min]->arrival))) {
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
           (queue->heap[parent(i)]->remaining > queue->heap[i]->remaining ||
            (queue->heap[parent(i)]->remaining == queue->heap[i]->remaining && queue->heap[parent(i)]->arrival > queue->heap[i]->arrival))) {
        Process* temp = queue->heap[parent(i)];
        queue->heap[parent(i)] = queue->heap[i];
        queue->heap[i] = temp;
        i = parent(i);
    }
}

void pop(PriorityQueue* queue) {
    queue->heap[0] = queue->heap[--queue->size];
    min_heapify(queue, 0);
}

int comparator(const void* a, const void* b) {
    Process lhs = *(Process*)a, rhs = *(Process*)b;

    if (lhs.arrival < rhs.arrival) {
        return -1;
    }
    if (lhs.arrival > rhs.arrival) {
        return 1;
    }
    return 0;
}

void display_process_table(char name[], Process* processes, int size) {
    int i;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;
    printf("\t\t\t%s\n", name);
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
            printf(" <- Ideal -> %.2f", gantt_chart.chart[i].end);
        } else {
            printf(" <- P%d -> %.2f", gantt_chart.chart[i].pid, gantt_chart.chart[i].end);
        }
    }
    printf("\n\n");
}
