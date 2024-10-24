#include <stdio.h>
int main () {
    int p;
    scanf("%d",&p);
    if (p>=0){
        printf("Whole no.");
        if (p>0)
        printf("& natural no.");
    }
    else
        printf("negative");
    return 0;

}