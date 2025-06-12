#include <stdio.h>

void swap(char *ch1, char *ch2) {
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void length(char *str) {
    int cnt;
    for (cnt = 0; str[cnt]; cnt++);
    printf("length of the string is %d", cnt);
}

void case_change(char *str) {
    int i;

    for (i = 0; str[i]; i++) {
        str[i] += 32;
    }
    printf("%s", str);
}

void case_change_toggle(char *str) {
    int i;

    for (i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    printf("%s", str);
}

void count_vowel_consonant(char *str) {
    int vowel = 0, consonant = 0, i;

    for (i = 0; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
                str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                vowel++;
            } else {
                consonant++;
            }
        }
    }
    printf("vowels -> %d\nconsonant -> %d", vowel, consonant);
}

void count_words(char *str) {
    int cnt = 1, i;

    for (i = 1; str[i]; i++) {
        if (str[i] == ' ' && str[i - 1] != ' ') {
            cnt++;
        }
    }
    printf("words -> %d", cnt);
}

void valid_string(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (
                  str[i] >= '0' && str[i] <= '9'))) {
            printf("Invalid String");
        }
    }
    printf("Valid String");
}

void reverse(char *str) {
    int cnt, i;
    char temp;
    for (cnt = 0; str[cnt]; cnt++);

    for (i = 0, cnt--; i < cnt; i++, cnt--) {
        temp = str[i];
        str[i] = str[cnt];
        str[cnt] = temp;
    }
    printf("reversed -> %s", str);
}

void compare_string(char *str1, char *str2) {
    int i = 0, j = 0;

    while (str1[i] && str2[j]) {
        if (str1[i] > str2[j]) {
            printf("%s is greater than %s", str1, str2);
            break;
        } else if (str1[i] < str2[j]) {
            printf("%s is smaller than %s", str1, str2);
            break;
        }
    }
    printf("Both string are equal");
}

void palindrome(char *str) {
    int cnt, i;
    char temp;
    for (cnt = 0; str[cnt]; cnt++);

    for (i = 0, cnt--; i < cnt; i++, cnt--) {
        if (str[i] != str[cnt]) {
            printf("String is not a palindrome");
            break;
        }
    }
    printf("String is a palindrome");
}

void find_duplicate(char *str) {
    int cnt = 0, i, j;

    for (i = 0; str[i]; i++) {
        for (j = i + 1; str[j]; j++) {
            if (str[i] != -1 && str[i] == str[j]) {
                cnt++;
                str[j] = -1;
            }
        }
        if (cnt) {
            printf("duplicate element %c\n", str[i]);
            cnt = 0;
        }
    }
}

void find_duplicate_hash(char *str) {
    int hash[26] = {0}, i;

    for (i = 0; str[i]; i++) {
        hash[str[i] - 97]++;
    }
    for (i = 0; i < 26; i++) {
        if (hash[i] > 1) {
            printf("duplicate element %c\n", i + 97);
        }
    }
}

void find_duplicate_bitwise(char *str) {
    int h = 0, x, i;

    for (i = 0; str[i]; i++) {
        x = 1 << (str[i] - 97);

        if (x & h) {
            printf("duplicate element %c\n", str[i]);
        } else {
            h |= x;
        }
    }
}

void anagram(char *str1, char *str2) {
    int hash[26] = {0}, i;

    for (i = 0; str1[i]; i++) {
        hash[str1[i] - 97]++;
    }
    for (i = 0; str2[i]; i++) {
        hash[str1[i] - 97]--;
    }
    for (i = 0; i < 26; i++) {
        if (hash[i]) {
            printf("it is not an anagram");
            return;
        }
    }
    printf("it is an anagram");
}

void permutation_recursion(char *str, int k) {
    static int array[4] = {0};
    static char result[4];

    if (str[k] == '\0') {
        result[k] = '\0';
        printf("%s\n", result);
    } else {
        int i;

        for (i = 0; str[i]; i++) {
            if (array[i] == 0) {
                result[k] = str[i];
                array[i]++;
                permutation_recursion(str, k + 1);
                array[i]--;
            }
        }
    }
}

void permutationSwap(char *str, int low, int high) {
    if (low == high) {
        printf("%s\n", str);
    } else {
        int i;

        for (i = low; str[i]; i++) {
            swap(&str[i], &str[low]);
            permutationSwap(str, low + 1, high);
            swap(&str[i], &str[low]);
        }
    }
}

int main() {
    char str[] = "dew";
    permutation_recursion(str, 0);
    return 0;
}
