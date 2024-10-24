#include <stdio.h>
#include <string.h>
int main(){
    char temp[10]= {'c','h','u','t','\0'};
    printf("%d",strlen(temp));
    char *lund;
    char gand[10];
    lund=temp;
    printf("%s",lund);
    strcpy(gand,temp);
    printf("%s", gand);
    return 0;
}