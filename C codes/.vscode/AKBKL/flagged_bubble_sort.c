#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void) {
    // flagged bubble sort
    int a[200]; int n;
    int r; int random;
    int t;
    int flag;
    n = 200;
    scanf("%d", &random); scanf("%d", &r);
    srand(random);
    for (int i = 1; i <= n - 1; i = 1 + i) {
        a[i] = r * (float)rand() / RAND_MAX;
    };
    printf("\nINPUT DATA......\n");
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);

    flag = n;
    while (flag != 0) {
        int k = flag - 1; flag = 0;
        for ( int j = 1; j <= k; j = j + 1) {
            if ( a[j] < a[j + 1] ) {
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                flag = j;
            };
        };
    };

    printf("\n\nSORTED DATA......\n");
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);
    return 0;
}