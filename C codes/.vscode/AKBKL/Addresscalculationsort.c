#include <stdio.h>
int main(void) {
    int data, a[1000];
// Address-calculation sort
// Takes multiple positive integers
    for (int i = 0; i <= 999; i++) a[i] = 0;
    printf("\nTO INDICATE END OF DATA, INPUT INVALID DATA\n");
    while (scanf("%d", &data)) {
        a[data] = a[data] + 1;
    };

    for (int i = 0; i <= 999; i++)
        if (a[i])
            for ( int j = 1; j <= a[i]; j++)
                printf("\n%d", i);
    return 0;
}