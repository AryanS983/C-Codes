#include <stdio.h>

int partition(int A[],int low,int high){
    int ref=A[low],i=low+1,j=high,temp;
    while(i<=j){
        while(A[i]<=ref){
            i++;
        }
        while(A[j]>ref){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[],int low, int high){
    int j;
    if(low<high){
        j=partition(A,low,high);
        quicksort(A,low,j-1);
        quicksort(A,j+1,high);
    }
}

void print(int *A,int high){
    int i;
    for(i=0;i<=high;i++){
        printf("%d ",A[i]);
    }
}

int main(){
    int A[]={85,4,8,77,8,4,8,86,7,51,2};
    quicksort(A,0,10);
    print(A,10);
    return 0;
}