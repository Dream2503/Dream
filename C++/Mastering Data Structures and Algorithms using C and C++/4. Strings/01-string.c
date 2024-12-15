#include <stdio.h>

void length(char *str) {
    int cnt = 0;
    while (str[cnt]) cnt++;
    printf("length of the string is %d", cnt);
}
void caseChange(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] += 32;
    printf("%s", str);
}
void caseChangeToggle(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        else if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
    }
    printf("%s", str);
}
void countVowelConsonant(char *str) {
    int vowel = 0, consonant = 0;
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'
            || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowel++;
            else consonant++;
        }
    }
    printf("vowels -> %d\nconsonant -> %d", vowel, consonant);
}
void countWords(char *str) {
    int cnt = 1;
    for (int i = 1; str[i]; i++) if (str[i] == ' ' && str[i-1] != ' ') cnt++;
    printf("words -> %d", cnt);
}
void validString(char *str) {
    for (int i = 0; str[i]; i++) if (!((str[i] >= 'A' && str[i] <= 'Z') ||
    (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))) printf("Invalid String");
    printf("Valid String");
}
void reverse(char *str) {
    int cnt = -1;
    char temp;
    for (int i = 0; str[i]; i++) cnt++;

    for (int i = 0; i < cnt; i++, cnt--) {
        temp = str[i];
        str[i] = str[cnt];
        str[cnt] = temp;
    }
    printf("reversed -> %s", str);
}
void compareString(char *str1, char *str2) {
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
    int cnt = -1;
    char temp;
    for (int i = 0; str[i]; i++) cnt++;

    for (int i = 0; i < cnt; i++, cnt--) 
        if (str[i] != str[cnt]) {
            printf("string is not a palindrome");
            break;
        }
    printf("reversed -> %s", str);
}
void findDuplicate(char *str) {
    int cnt = 0;

    for (int i = 0; str[i]; i++) {
        for (int j = i + 1; str[j]; j++) if (str[i] == str[j]) cnt++;
        if (cnt) {
            printf("duplicate element %c\n", str[i]);
            cnt = 0;
        }
    }
}
void findDuplicateHash(char *str) {
    int hash[26] = {0};
    for (int i = 0; str[i]; i++) hash[str[i]-97]++;
    for (int i = 0; i < 26; i++) if (hash[i] > 1) printf("duplicate element %c\n", i+97);
}
void findDuplicateBitwise(char *str) {
    int h = 0, x;

    for (int i = 0; str[i]; i++) {
        x = 1;
        x = x << (str[i] - 97);
        if (x & h) printf("duplicate element %c\n", str[i]);
        else h = x | h;
    }
}
void anagram(char *str1, char *str2) {
    int hash[26] = {0};
    for (int i = 0; str1[i]; i++) hash[str1[i]-97]++;
    for (int i = 0; str2[i]; i++) 
        if (--hash[str2[i]-97] == -1) {
            printf("it is not an anagram");
            return;
        }
    printf("it is an anagram");
}

void permutationRecursion(char *str, int k) {
    static int array[4] = {0};
    static char result[4];

    if (k == 3) {
        result[k] = 0;
        printf("%s\n", result);
    } else {
        for (int i = 0; str[i]; i++)
            if (!array[i]) {
                result[k] = str[i];
                array[i]++;
                permutationRecursion(str, k+1);
                array[i]--;
            }
    }
}
void permutationSwap(char *str, int low, int high) {
    static char temp;
    if (low == high) {
        printf("%s\n", str);
    } else
        for (int i = low; str[i]; i++) {
            temp = str[i];
            str[i] = str[low];
            str[low] = temp;
            permutationSwap(str, low+1, high);
            temp = str[low];
            str[low] = str[i];
            str[i] = temp;
        }
}

int main() {
    char str[] = "ABC";
    permutationSwap(str, 0, 2);
    return 0;
}