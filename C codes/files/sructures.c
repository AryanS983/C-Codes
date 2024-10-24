#include <stdio.h>
#include <string.h>
struct student {
    int id;
    char stdname[50];
    int roll_no;
} ;

int main () {
    struct student Harry, Ravi, Shubham;
    Harry.id = 1;
    Harry.roll_no = 45;
    strcpy(Harry.stdname, "lol ho gaya");
    printf("%s",Harry.stdname);
    return 0;
}
