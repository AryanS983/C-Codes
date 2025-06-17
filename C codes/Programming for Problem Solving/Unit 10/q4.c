#include <stdio.h>

struct Student {
    char name[20];
    int roll;
};

int main() {
    struct Student s;

    // Input values
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    // Write to file in simple format
    FILE *fp = fopen("info.txt", "w");
    fprintf(fp, "%s %d\n", s.name, s.roll);
    fclose(fp);

    // Read back from file (not using structure here)
    char name[20];
    int roll;
    fp = fopen("info.txt", "r");
    fscanf(fp, "%s %d", name, &roll);
    fclose(fp);

    // Output
    printf("Read from file:\n");
    printf("Name: %s, Roll: %d\n", name, roll);

    return 0;
}
