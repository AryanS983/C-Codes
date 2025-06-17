#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    char ch;

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    ch = fgetc(fp);               // first read
    while (ch != EOF) {
        putchar(ch);              // print character
        ch = fgetc(fp);           // read next character
    }

    fclose(fp);
    return 0;
}
