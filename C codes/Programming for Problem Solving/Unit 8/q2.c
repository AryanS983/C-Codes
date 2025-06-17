#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student s[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter details of student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nStudent Details:\n");
    for (i = 0; i < 3; i++) {
        printf("Student %d: %s, Age: %d, Marks: %.2f\n",
               i + 1, s[i].name, s[i].age, s[i].marks);
    }

    return 0;
}
