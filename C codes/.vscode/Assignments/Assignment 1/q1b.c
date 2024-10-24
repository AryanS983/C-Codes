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
    printf("\nArray before deletion\n");
    for (i=0;i<x;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the position of element to be deleted - "); scanf("%d", &pos);
    for (i=(pos-1);i<x;i++){
        arr[i]=arr[i+1];
    }
    x=x-1;
    printf("\nArray After deletion\n");
    for (i=0;i<x;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
