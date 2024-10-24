#include <stdio.h>
#define max 10
void insertion(int arr[max],int n){
    int i,j=1,temp;
    while(j<n){
        temp =arr[j];
        for (i=j-1;i>=0 && temp<arr[i];i--){

            arr[i+1]=arr[i];
        }
        arr[i+1]=temp;
        j++;
    }
}

int main (){
    int arr[max]={45,13,5,7,16,50,8};
    printf("Unsorted: ");
    for (int i=0; i<7;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    insertion(arr,7);
    printf("Sorted: ");
    for (int i=0; i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}