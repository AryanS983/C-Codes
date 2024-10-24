#include <stdio.h>

void swap(int * a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int A[],int high){
    int i;
    for(i=0;i<=high;i++){
        printf("%d ",A[i]);
    }
}

int main(){
    int A[]={86,8,77,44,7,1,4,87,45};
    swap(&A[0],&A[5]);
    print(A,7);
    
    return 0;
}
