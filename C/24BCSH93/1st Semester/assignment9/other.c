#include <stdio.h>

int substr(char[], char[]);
void _remove(char[], char[], int);

int main() {
    char str[100] = "Receive three character from the keyboard";
    char key[10] = "the";
    int pos = substr(str, key);
    _remove(str, key, pos);
    printf("Modified string is %s\n", str);
    return 0;
}

int substr(char str[], char key[]) {
    int i, j, res, flag = 1, curr;

    for (i = 0; str[i]; i++) {
        curr = i;

        if (str[i] == key[0]) {
            res = i;

            for (j = 0; key[j] && str[i]; j++, i++) {
                if (str[i] != key[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return res;
            }
        }
        i = curr;
        flag = 1;
    }
    return -1;
}

void _remove(char str[], char key[], int pos) {
    int keySize, strSize, i;
    for (keySize = 0; key[keySize]; keySize++)
        ;
    for (strSize = 0; str[strSize]; strSize++)
        ;

    if (pos + keySize > strSize) {
        str[pos] = '\0';
    } else {
        for (i = pos; i < strSize; i++) {
            str[i] = str[i + keySize];
        }
        str[i] = '\0';
    }
}
