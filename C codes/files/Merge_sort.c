#include <stdio.h>

void merge (int A[], int low, int mid, int high){
    int i=low, j=mid+1, k=0;
    int Temp[100];
    while (i<=mid && j<=high){
        if (A[i]< A[j]){
            Temp[k]=A[i];
            k++;i++;
        }
        else {
            Temp[k]=A[j];
            k++;j++;
        }
    }
    while (i<=mid){
        Temp[k]=A[i];
        k++;i++;
    }
    while (j<=high){
        Temp[k]= A[j];
        k++;j++;
    }
    for (i=low, j=0;i<=high ; i++, j++){
        A[i]=Temp[j];
    }
}

void mergesort(int A[], int low , int high ){
    int mid;
    if (low < high ){
        mid = (low + high )/ 2 ;
        mergesort (A ,low, mid );
        mergesort (A, mid+1, high);
        merge (A, low, mid,high);
    }
}




int main (){
    int i;
    int A[]= {7,5,6,16,2} ;
    for (i=0;i<5;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    mergesort(A,0,4);
    for (i=0;i<5;i++){
        printf("%d ", A[i]);
    }
    return 0;
}