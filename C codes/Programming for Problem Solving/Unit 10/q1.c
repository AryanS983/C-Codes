#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w"); // Open file for writing

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Hello, this is a file writing example.\n");
    fprintf(fp, "File handling in C is easy!\n");

    fclose(fp); // Close the file

    printf("Data written to file successfully.\n");
    return 0;
}
