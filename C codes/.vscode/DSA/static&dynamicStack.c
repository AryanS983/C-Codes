#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int a[15];
    int b[15];
    int *c;
    int *d;
    int j = 15;
// more arrays
// Arrays a, b, c & d are four different ways of declaring and handling arrays.
// All four arrays are reading the same 15 values, 0 - 14.

    c = malloc(j * sizeof(int));
    d = malloc(j * sizeof(int));
    for (int i = 0; i <= 14; i++) {
        scanf("%d", &a[i]);
        scanf("%d", b+i);
        scanf("%d", &c[i]);
        scanf("%d", d+i);
    }
    printf(" a b c d\n");
    for (int i = 0; i <= 14; i++) {
        printf("%2d %2d %3d %2d\n", a[i], b[i], c[i], d[i]);
    }
    return 0;
}