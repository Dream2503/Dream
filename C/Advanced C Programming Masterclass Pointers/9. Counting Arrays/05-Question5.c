#include <stdio.h>
#include <stdlib.h>

int areAllLettersIncluded(char *seq1, int size1, char *seq2, int size2) {
    int *cntArray1 = (int*)calloc(26, sizeof(int)), *cntArray2 = (int*)calloc(26, sizeof(int));
    int rtn;

    for (int i = 0; i < size1; i++)
        cntArray1[seq1[i] - 'a']++;
    
    for (int i = 0; i < size2; i++)
        cntArray2[seq2[i] - 'a']++;
    
    for (int i = 0; i < size2; i++) {
        if (cntArray1[seq2[i] - 'a'] >= cntArray2[seq2[i] - 'a'])
            rtn = 1;
        else
            rtn = 0;
    }
    free(cntArray1);
    free(cntArray2);
    return rtn;
}

int main() {
    char seq1[3] = {'d','o','g'}, seq2[3] = {'c', 'a', 't'};
    printf("%d", areAllLettersIncluded(seq1, 3, seq2, 3));
    return 0;
}
