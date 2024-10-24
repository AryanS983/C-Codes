#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void) {
// binary insertion sort
    int a[200]; int n;
    int s, random;
    int t;
    int l, r, m;

    n = 200;
    scanf("%d", &random); scanf("%d", &s);
    srand(random);
    for (int i = 1; i <= n - 1; i = 1 + i) {
        a[i] = s * (float)rand() / RAND_MAX;
    };
    printf("\nINPUT DATA......\n");
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);

    for (int j = 2; j <= n - 1; j++) {
        t = a[j]; l = 1; r = j - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (t < a[m]) r = m - 1;
            else l = m + 1;
        }
        for (m = j - 1; m >= l; m--) a[m + 1] = a[m];
        a[l] = t;
    }

    printf("\n\nSORTED DATA......\n");
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);
    return 0;
}