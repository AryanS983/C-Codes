#include <stdio.h>

int main() {
    int arr[5], i, key, found = 0;

    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    for (i = 0; i < 5; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Number found at position %d\n", i + 1);
    else
        printf("Number not found.\n");

    return 0;
}
