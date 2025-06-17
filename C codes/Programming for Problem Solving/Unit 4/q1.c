#include <stdio.h>

int main() {
    int numbers[5], max, i;

    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }

    max = numbers[0];

    for (i = 1; i < 5; i++) {
        if (numbers[i] > max)
            max = numbers[i];
    }

    printf("Maximum number is: %d\n", max);

    return 0;
}
