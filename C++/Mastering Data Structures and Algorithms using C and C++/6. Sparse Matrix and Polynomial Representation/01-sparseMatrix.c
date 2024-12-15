#include <stdio.h>
#include <stdlib.h>
typedef struct Element {int i, j, value} Element;
typedef struct Sparse {
    int m, n, size;
    Element *array;
} Sparse;

void create(Sparse *matrix) {
    printf("Enter Dimensions: "); scanf("%d%d", &matrix->m, &matrix->n);
    printf("Number of non-zero: "); scanf("%d", &matrix->size);
    matrix->array = (Element *)malloc(matrix->size*sizeof(Element));
    printf("Enter non-zero Elements:\n");
    for (int i = 0; i < matrix->size; i++) scanf("%d%d%d", &matrix->array[i].i, &matrix->array[i].j, &matrix->array[i].value);
}
void display(Sparse matrix) {
    int k = 0;

    for(int i = 0; i < matrix.m; i++) {
        for(int j = 0; j < matrix.n; j++) {
            if(i == matrix.array[k].i && j == matrix.array[k].j) printf("%d " ,matrix.array[k++].value);
            else printf("0 ");
        }
        printf("\n");
    }
}

Sparse * add(Sparse *matrix1 ,Sparse *matrix2) {
    Sparse *sum;
    int i = 0, j = 0, k = 0;
    if (matrix1->n != matrix2->n && matrix1->m != matrix2->m) return NULL;
    sum = (Sparse *)malloc(sizeof(Sparse));
    sum->array = (Element *)malloc((matrix1->size+matrix2->size)*sizeof(Element));

    while(i < matrix1->size && j < matrix2->size) {
        if (matrix1->array[i].i < matrix2->array[j].i) sum->array[k++] = matrix1->array[i++];
        else if(matrix1->array[i].i > matrix2->array[j].i) sum->array[k++] = matrix2->array[j++];
        else {
            if(matrix1->array[i].j < matrix2->array[j].j) sum->array[k++] = matrix1->array[i++];
            else if(matrix1->array[i].j > matrix2->array[j].j) sum->array[k++] = matrix2->array[j++];
            else {
                sum->array[k] = matrix1->array[i];
                sum->array[k++].value = matrix1->array[i++].value + matrix2->array[j++].value;
            }
        }
    }
    for(; i < matrix1->size; i++) sum->array[k++] = matrix1->array[i];
    for(; j < matrix2->size; j++) sum->array[k++] = matrix2->array[j];
    sum->m = matrix1->m;
    sum->n = matrix1->n;
    sum->size = k;
    return sum;
}

int main()
{
    Sparse matrix1,matrix2,*matrix3;
    create(&matrix1);
    create(&matrix2);
    matrix3 = add(&matrix1, &matrix2);
    printf("First Matrix\n");
    display(matrix1);
    printf("Second Matrix\n");
    display(matrix2);
    printf("Sum Matrix\n");
    display(*matrix3);
    return 0;
}