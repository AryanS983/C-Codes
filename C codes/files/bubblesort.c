#include <stdio.h>

void bubblesort(int A[], int n) {
    int temp;
    int i, j;
    for (i=0;i<n-1; i++){
        for (j=0; j<n-1-i; j++){
            if (A[j]>A[j+1]){
                temp= A[j];
                A[j]= A[j+1];
                A[j+1]=temp;

            }
        }
    }
}
void adaptivebubblesort(int A[], int n){
    int temp;
    int i, j;
    int issorted;
    for (i=0;i<n-1; i++){
        issorted =1;
        printf("pass no %d \n", i+1);
        for (j=0; j<n-1-i; j++){
            if (A[j]>A[j+1]){
                temp= A[j];
                A[j]= A[j+1];
                A[j+1]=temp;
                issorted=0;
            }
        }
        if (issorted){
            break;
        }
    }
}

int main () {
    int i;
    // int A[]= {2,7,6,8,10,14,3,1};
    int A[]={1,2,3,4,5,6,7,8};
    adaptivebubblesort(A,8);
    for (i=0; i<8 ; i++){
        printf("%d ",A[i] );
    }
    return 0;
}