#include <stdio.h>

int main(){
    char ar[10]="Hello";
    ar[2]='5';
    int i=0;
    printf("%s", ar);
    while(ar[i]!='\0'){
        printf("%c", ar[i]);
        i++;
    }
    // here strings are mutable
    return 0;
}