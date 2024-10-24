#include <stdio.h>
int i,j;
void addPolynomials(int poly1[], int poly2[], int result[], int degree) {

    for ( i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

void multiplyPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for( i = 0; i <= 2 * degree; i++) {
        result[i] = 0;
    }

    for( i = 0; i <= degree; i++) {
        for( j = 0; j <= degree; j++) {
            result[i + j] += poly1[i] * poly2[j];  /*<------- This line is the crux of this code */
        }
    }
}

void printPolynomial(int poly[], int degree) {
    for ( i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i > 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int degree;
    printf("Enter the maximum  degree: ");
    scanf("%d", &degree);
    int poly1[degree];
    int poly2[degree];
    printf("Enter the coefficients of polynomial 1: ");
    for(i= degree; i>=0; i--){
     scanf("%d", &poly1[i]);
     }
     printf("Enter the coefficients of polynomial 2: ");
     for(i= degree; i>=0; i--){
     scanf("%d", &poly2[i]);
     }
    int resultAdd[4], resultMultiply[7];

    addPolynomials(poly1, poly2, resultAdd, degree);
    multiplyPolynomials(poly1, poly2, resultMultiply, degree);

    printf("Polynomial 1: ");
    printPolynomial(poly1, degree);

    printf("Polynomial 2: ");
    printPolynomial(poly2, degree);

    printf("Addition Result: ");
    printPolynomial(resultAdd, degree);

    printf("Multiplication Result: ");
    printPolynomial(resultMultiply, 2 * degree);

    return 0;
}
