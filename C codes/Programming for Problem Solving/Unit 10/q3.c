#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "a");

    if (fp == NULL) {
        printf("Can't open file.\n");
        return 1;
    }

    fprintf(fp, "Appended line\n");
    fclose(fp);

    printf("Data added.\n");
    return 0;
}
