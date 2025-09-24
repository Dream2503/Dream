#include <stdlib.h>
#include <string.h>

int commonChild(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);

    if (m < n) {
        int temp1 = m;
        m = n;
        n = temp1;
        char* temp2 = s1;
        s1 = s2;
        s2 = temp2;
    }
    int *c = (int*)malloc((n + 1) * sizeof(int)), i, j, prev, current;

    for (i = 0; i <= n; i++) {
        c[i] = 0;
    }
    for (i = 1; i <= m; i++) {
        prev = c[0];
        current = c[1];

        for (j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                c[j] = prev + 1;
            } else if (c[j] < c[j - 1]) {
                c[j] = c[j - 1];
            }
            prev = current;

            if (j < n) {
                current = c[j + 1];
            }
        }
    }
    int res = c[n];
    free(c);
    return res;
}
