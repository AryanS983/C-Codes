#include <stdio.h>
int main () {
    int n , i;
    printf("enter the number you want the table of : ");
    scanf("%d", &n);
    printf("the table of %d is: ",n);
    for (i=1 ; i<=10 ; i++){
        printf("%d x %d = %d \n",n,i,n*i);
    }
    return 0;
}