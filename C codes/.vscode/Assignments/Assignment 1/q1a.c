#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
int main(){
    int arr[max], i, x,temp, pos;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&x);
    for (i=0;i<x;i++){
        temp=rand()%max;
        arr[i]=temp;
    }
    printf("Array before insersion\n");
    for (i=0;i<x;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the Element to be inserted - "); scanf("%d",&temp);
    printf("Enter the position to be inserted - "); scanf("%d",&pos);
    for (i=x;i>=(pos-1);i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=temp;
    x=x+1;
    printf("\nArray After insersion\n");
     for (i=0;i<x;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}