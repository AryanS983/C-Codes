#include <stdio.h>



int partition (int A[], int low, int high){
    int temp;
    int pivot = A[low] , i= low +1 , j= high;
    do {
        while (A[i]<=pivot){
            i++;
        }
        while (A[j]>pivot) {
            j--;
        }
        if (i<j){
            temp= A[i];
            A[i]=A[j];
            A[j]= temp;
        }
    }  while (i<j);
    
    temp= A[low];
    A[low]=A[j];
    A[j]= temp;

    return j;
}


void quicksort(int A[], int low , int high ) {
    int partitionindex;
    if (low < high){
        partitionindex = partition(A, low, high);
        quicksort(A, low , partitionindex -1);
        quicksort( A, partitionindex + 1 , high);
    }
}



int main () {
    int a;
    int A[] = {9,5,14,12,7,13,1,16,22,2,20};
    quicksort(A,0,10);
    for (a=0; a<11; a++){
        printf("%d ", A[a]);
    }
    return 0;
}