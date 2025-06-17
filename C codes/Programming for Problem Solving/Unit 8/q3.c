#include <stdio.h>

struct Date {
    int day, month, year;
};

struct Student {
    char name[50];
    struct Date dob;  // nested structure
};

int main() {
    struct Student s;

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);

    printf("\nName: %s\n", s.name);
    printf("DOB: %02d-%02d-%d\n", s.dob.day, s.dob.month, s.dob.year);

    return 0;
}
