//  Q3. Implementation of Robin Karp String Matching Algorithm.

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void robin_karp_match(char*, int, char*, int, int, int);

int main() {
    int string_size, pattern_size;
    printf("Enter the size of the string and the pattern: ");
    scanf("%d%d", &string_size, &pattern_size);
    char *string = (char*)malloc(string_size * sizeof(char)), *pattern = (char*)malloc(pattern_size * sizeof(char));
    printf("Enter the string and the pattern: ");
    scanf("%s%s", string, pattern);

    if (!string || !pattern) {
        printf("Memory was not allocated");
        exit(0);
    }
    robin_karp_match(string, string_size, pattern, pattern_size, (1 << (sizeof(char) * 8)) - 1, INT32_MAX);
    free(pattern);
    free(string);
}

void robin_karp_match(char* string, int string_size, char* pattern, int pattern_size, int radix, int mod) {
    bool found;
    int h = (int64_t)powl(radix, pattern_size - 1) % mod, p = 0, s = 0, i, j;

    for (i = 0; i < pattern_size; i++) {
        p = ((int64_t)radix * p + pattern[i]) % mod;
        s = ((int64_t)radix * s + string[i]) % mod;
    }
    printf("The pattern %s in string %s occurs at: ", pattern, string);

    for (i = 0; i <= string_size - pattern_size; i++) {
        if (p == s) {
            found = true;

            for (j = 0; j < pattern_size; j++) {
                if (string[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                printf("%d ", i);
            }
        }
        if (i < string_size - pattern_size) {
            s = ((int64_t)radix * (s - string[i] * h) + string[i + pattern_size]) % mod;
        }
    }
    printf("\n");
}
