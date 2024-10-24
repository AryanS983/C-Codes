#include <stdio.h>

void insersionsort(int A[],int n ){
    int i, j;
    int key;
    for (i=1; i<n; i++){
        key =A[i];
        j=i-1;
        while (j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main () {
    int i;
    int A[]= {5,4,8,1,6,10,7,1,2};
    insersionsort(A,9);
    for (i=0; i<9; i++){
        printf("%d ", A[i]);
    }
    return 0;
}