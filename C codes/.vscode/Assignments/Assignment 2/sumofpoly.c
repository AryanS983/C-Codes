#include <stdio.h>
#include <stdlib.h>
#define max 100
void display (int p[max],int deg) {
    int i;
     for (i=deg;i>=0;i--){
        printf("%dx^%d ",p[i],i);
        if(i!=0) printf("+ ");
    }
}
void input (int *p, int deg){
    int i;
    for (i=0;i<=deg;i++){
        printf("a%d : ",i); scanf("%d", p+i);
    }
}

int main() {
    int p1[max],p2[max],p3[max],i,deg;
    printf("Enter the maximum degree of polynomial : ");
    scanf("%d",&deg);
    printf("\nEnter the coefficients of the first polynomial:- \n");
    input(p1,deg);
    printf("The first polynomial is ");
    display(p1, deg);
    printf("\nEnter the coefficients of the second polynomial:- \n");
    input(p2,deg);
    printf("The second polynomial is ");
    display(p2, deg);
    printf("\nSum of both polynomials is : ");
    for (i=0;i<=deg;i++){
        p3[i]=p1[i]+p2[i];
    }
    display(p3,deg);
    return 0;
}
