#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main(void) {
    // insertion sort with sentinel
    int a[10000]; int n;
    int r;
    int t, k;
    clock_t start, end;

    n = 10000;
    r = 8000; // scale
    srand(time(0));
    for (int i = 1; i <= n - 1; i = 1 + i) {
        a[i] = r * (float)rand() / RAND_MAX;
    };
    /*printf("\nINPUT DATA......\n");*/
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);

    start = clock();
    a[0] = INT_MIN;
// comment out this line to run without sentnel
    for (int i = 2; i <= n - 1; i = i + 1) {
        t = a[i]; k = i - 1;
        while (t < a[k] && k >= 1 ) { //&& k >= 1
        // uncomment and then include in while clause to run without sentinel
            a[k + 1] = a[k]; k = k - 1;
        };
        a[k + 1] = t;
    };
    end = clock();
    /*printf("\n\nSORTED DATA......\n");*/
    for (int i = 1; i <= n - 1; i = 1 + i) printf("\na[%d] = %d", i, a[i]);
    double dur = (end - start);
    dur = dur / CLOCKS_PER_SEC;
// printf("\nTime in seconds without sentinel is %f", dur);
    printf("\nTime in seconds with sentinel is %f", dur);
    return 0;
}