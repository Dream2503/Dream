#include <stdlib.h>

void merge_sort(int** obstacles, int** sorted, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(obstacles, sorted, low, mid);
        merge_sort(obstacles, sorted, mid + 1, high);
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (obstacles[i][0] < obstacles[j][0]) {
                sorted[k++] = obstacles[i++];
            } else if (obstacles[i][0] > obstacles[j][0]) {
                sorted[k++] = obstacles[j++];
            } else {
                if (obstacles[i][1] <= obstacles[j][1]) {
                    sorted[k++] = obstacles[i++];
                } else {
                    sorted[k++] = obstacles[j++];
                }
            }
        }
        while (i <= mid) {
            sorted[k++] = obstacles[i++];
        }
        while (j <= high) {
            sorted[k++] = obstacles[j++];
        }
        for (i = low; i <= high; i++) {
            obstacles[i] = sorted[i];
        }
    }
}

int binary_search(int x, int y, int** obstacles, int k) {
    int low = 0, high = k - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (obstacles[mid][0] < x) {
            low = mid + 1;
        } else if (obstacles[mid][0] > x) {
            high = mid - 1;
        } else {
            if (obstacles[mid][1] < y) {
                low = mid + 1;
            } else if (obstacles[mid][1] > y) {
                high = mid - 1;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles) {
    int i, j, res = 0;
    int** sorted = (int**)malloc(sizeof(int*) * k);

    if (!sorted) {
        exit(0);
    }
    merge_sort(obstacles, sorted, 0, k - 1);
    for (i = c_q - 1; i > 0; i--) {
        if (binary_search(r_q, i, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = c_q + 1; i <= n; i++) {
        if (binary_search(r_q, i, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = r_q - 1; i > 0; i--) {
        if (binary_search(i, c_q, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = r_q + 1; i <= n; i++) {
        if (binary_search(i, c_q, obstacles, k)) {
            break;
        }
        res++;
    }

    for (i = r_q - 1, j = c_q - 1; i > 0 && j > 0; i--, j--) {
        if (binary_search(i, j, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = r_q + 1, j = c_q + 1; i <= n && j <= n; i++, j++) {
        if (binary_search(i, j, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = r_q - 1, j = c_q + 1; i > 0 && j <= n; i--, j++) {
        if (binary_search(i, j, obstacles, k)) {
            break;
        }
        res++;
    }
    for (i = r_q + 1, j = c_q - 1; i <= n && j > 0; i++, j--) {
        if (binary_search(i, j, obstacles, k)) {
            break;
        }
        res++;
    }
    free(sorted);
    return res;
}
