#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }

        i++;
        swap(&arr[i],&arr[high]);
        return i;
    }
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {5,7,10,4,23,6};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n-1);
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}