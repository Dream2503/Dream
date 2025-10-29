#include "util.h"

GanttChart FCFS(Process*, int);
GanttChart SJF(Process*, int);

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
        printf("Enter the PID, Arrival and Burst time of %dth process: ", i + 1);
        scanf("%d%f%f", &processes[i].pid, &processes[i].arrival, &processes[i].burst);
    }
    gantt_chart = FCFS(processes, size);
    display_process_table("FIRST-COME-FIRST-SERVE ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    gantt_chart = SJF(processes, size);
    display_process_table("SHORTEST-JOB-FIRST ALGORITHM", processes, size);
    display_gantt_chart(gantt_chart);
    free(gantt_chart.chart);

    free(processes);
    return 0;
}

GanttChart FCFS(Process* processes, int size) {
    int i = 0;
    float current = 0;
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 2 * sizeof(GanttChartElement)), 0};

    if (!gantt_chart.chart) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    qsort(processes, size, sizeof(Process), comparator);

    for (i = 0; i < size; i++) {
        if (current < processes[i].arrival) {
            current = processes[i].arrival;
            GanttChartElement element = {-1, current};
            gantt_chart.chart[gantt_chart.size++] = element;
        }
        processes[i].response = processes[i].waiting = current - processes[i].arrival;
        current += processes[i].burst;
        processes[i].turnaround = current - processes[i].arrival;
        GanttChartElement element = {processes[i].pid, current};
        gantt_chart.chart[gantt_chart.size++] = element;
    }
    return gantt_chart;
}

GanttChart SJF(Process* processes, int size) {
    int i = 0;
    float current = 0;
    PriorityQueue queue = {(Process**)malloc(size * sizeof(Process*)), 0};
    GanttChart gantt_chart = {(GanttChartElement*)malloc(size * 2 * sizeof(GanttChartElement))};

    if (!gantt_chart.chart) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    qsort(processes, size, sizeof(Process), comparator);

    while (i < size) {
        processes[i].remaining = processes[i].burst;
        push(&queue, &processes[i++]);

        while (queue.size) {
            Process* process = queue.heap[0];
            pop(&queue);

            if (current < process->arrival) {
                current = process->arrival;
                GanttChartElement element = {-1, current};
                gantt_chart.chart[gantt_chart.size++] = element;
            }
            process->response = process->waiting = current - process->arrival;
            current += process->burst;
            process->remaining = 0;
            process->turnaround = current - process->arrival;
            GanttChartElement element = {process->pid, current};
            gantt_chart.chart[gantt_chart.size++] = element;

            while (i < size && processes[i].arrival <= current) {
                processes[i].remaining = processes[i].burst;
                push(&queue, &processes[i++]);
            }
        }
    }
    return gantt_chart;
}
