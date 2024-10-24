#include <stdio.h>

void merge(int A[],  int mid, int low, int high){
    int i=low, j=mid+1, k=low, B[100];

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }
}

void mergesort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,mid,low,high);
    }
}

int main(){
    int A[]={10,30,5,4,8,49,7,1,68,12};
    int low=0,high=9,i;
    mergesort(A,low,high);
    for(i=0;i<=high;i++){
        printf("%d ",A[i]);
    }
    return 0;
}