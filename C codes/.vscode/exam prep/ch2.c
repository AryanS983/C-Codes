#include <stdio.h>
int main (){
    int sal = 28000;
    char gen='M';
    int t=0;
    if (gen=='F')
        if (sal>30000)
            t=sal-30000;
    else 
        printf("no tax");
    else
        printf("ham ladke hai janab");
    printf(" %d", t);
    return 0;
}