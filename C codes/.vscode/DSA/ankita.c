#include <stdio.h>
struct stu  //making a struct named stu
{
    int Sroll;
    char Sname[20];
    int marks[5];
};
int main(){
    struct stu s;  //declaration
    int total=0, i ; float avg;
    printf("Enter Sroll:");
    scanf("%d",&s.Sroll);
    printf("Enter Sname:");
    scanf("%s",&s.Sname);
    printf("Enter 5 sub Smarks:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&s.marks[i]);
        total=total+s.marks[i];
    }

    avg = (float)total/5;
    printf("Sroll: %d\n",s.Sroll);
    printf("Sname: %s\n",s.Sname);
    printf("Stotal: %d\n",total);
    printf("Savg: %f\n",avg);
    return 0;

}