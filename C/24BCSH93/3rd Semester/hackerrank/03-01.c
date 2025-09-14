#include <stdlib.h>

char* highestValuePalindrome(char* s, int n, int k) {
    int i, j, cnt = 0;
    int* changed = (int*)malloc(sizeof(int) * n / 2);

    for (i = 0, j = n - 1; i < j; i++, j--) {
        changed[i] = 0;

        if (s[i] != s[j]) {
            s[i] = s[j] = s[i] > s[j] ? s[i] : s[j];
            changed[i] = 1;
            cnt++;
        }
    }
    if (cnt > k) {
        free(changed);
        return "-1";
    }
    k -= cnt;

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != '9') {
            if (changed[i] && k >= 1) {
                s[i] = s[j] = '9';
                k--;
            } else if (!changed[i] && k >= 2) {
                s[i] = s[j] = '9';
                k -= 2;
            }
        }
    }
    if (n % 2 == 1 && k > 0) {
        s[n / 2] = '9';
    }
    free(changed);
    return s;
}
