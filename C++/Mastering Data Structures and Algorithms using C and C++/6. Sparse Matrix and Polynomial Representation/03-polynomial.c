#include <stdio.h>
#include<stdlib.h>

typedef struct Term {int coEfficient, exponent;} Term;
typedef struct Poly {
    int size;
    Term *terms;
} Poly;

void create(Poly *polynomial) {
    printf("Enter Number of terms: "); scanf("%d", &polynomial->size);
    polynomial->terms = (Term*)malloc(polynomial->size*sizeof(Term));
    printf("Enter terms\n");
    for(int i = 0; i < polynomial->size; i++) scanf("%d%d", &polynomial->terms[i].coEfficient, &polynomial->terms[i].exponent);
}
void display(Poly polynomial) {
    for(int i = 0; i < polynomial.size; i++) printf("%dx%d+", polynomial.terms[i].coEfficient, polynomial.terms[i].exponent);
    printf("\n");
}
Poly *add(Poly *polynomial1, Poly *polynomial2)
{
    int i = 0, j = 0, k = 0;
    Poly *sum = (Poly*)malloc(sizeof(Poly));
    sum->terms = (Term*)malloc((polynomial1->size+polynomial2->size)*sizeof(Term));

    while (i < polynomial1->size && j < polynomial2->size) {
        if(polynomial1->terms[i].exponent > polynomial2->terms[j].exponent) sum->terms[k++] = polynomial1->terms[i++];
        else if(polynomial1->terms[i].exponent < polynomial2->terms[j].exponent) sum->terms[k++] = polynomial2->terms[j++];
        else {
            sum->terms[k].exponent = polynomial1->terms[i].exponent;
            sum->terms[k++].coEfficient = polynomial1->terms[i++].coEfficient + polynomial2->terms[j++].coEfficient;
        }
    }
    for(; i < polynomial1->size; i++) sum->terms[k++] = polynomial1->terms[i];
    for(; j < polynomial2->size; j++) sum->terms[k++] = polynomial2->terms[j];
    sum->size = k;
    return sum;
}

int main() {
    Poly polynomial1, polynomial2, *polynomial3;
    create(&polynomial1);
    create(&polynomial2);
    polynomial3 = add(&polynomial1, &polynomial2);
    printf("\n");
    display(polynomial1);
    printf("\n");
    display(polynomial2);
    printf("\n");
    display(*polynomial3);
    return 0;
}