#include <stdio.h>
#include <math.h>
#include <conio.h>
int main () {
    int N,i;
    float sum=0;
    printf("Enter the integer X: ");
    scanf("%d",&N);
    printf("\n 1");
    for (i=1;i<=N;i++){
        if(i>1){
            printf("+1/%d",i);
            sum=sum+(1/(float)i);
        }
        else{
            sum=sum+(1/(float)i);
        }
    }
    printf("\n\nThe required sum is = %f",sum);
    getch();
    
}