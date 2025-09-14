char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    int i, j, k;
    *result_count = grid_count;

    if (n == 1) {
        return grid;
    }
    if (n % 2 == 0) {
        for (i = 0; i < grid_count; i++) {
            for (j = 0; grid[i][j]; j++) {
                grid[i][j] = 'O';
            }
        }
        return grid;
    }
    int steps = n % 4 == 3 ? 1 : 2;

    for (k = 0; k < steps; k++) {
        for (i = 0; i < grid_count; i++) {
            for (j = 0; grid[i][j]; j++) {
                if (grid[i][j] == '.') {
                    grid[i][j] = 'O';
                } else {
                    grid[i][j] = 'D';
                }
            }
        }
        for (i = 0; i < grid_count; i++) {
            for (j = 0; grid[i][j]; j++) {
                if (grid[i][j] == 'D') {
                    if (j > 0 && grid[i][j - 1] != 'D') {
                        grid[i][j - 1] = 'X';
                    }
                    if (i > 0 && grid[i - 1][j] != 'D') {
                        grid[i - 1][j] = 'X';
                    }
                    if (grid[i][j + 1] && grid[i][j + 1] != 'D') {
                        grid[i][j + 1] = 'X';
                    }
                    if (i + 1 < grid_count && grid[i + 1][j] != 'D') {
                        grid[i + 1][j] = 'X';
                    }
                }
            }
        }
        for (i = 0; i < grid_count; i++) {
            for (j = 0; grid[i][j]; j++) {
                if (grid[i][j] == 'D' || grid[i][j] == 'X') {
                    grid[i][j] = '.';
                } else {
                    grid[i][j] = 'O';
                }
            }
        }
    }
    return grid;
}
