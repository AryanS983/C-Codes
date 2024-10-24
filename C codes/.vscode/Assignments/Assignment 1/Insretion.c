#include <stdio.h>

int main(){
        int arr[1000]={23, 25, 33, 35, 45, 53}, capacity=1000;
        int n=6; //no. of elements pesent in the array
        int index,i;
        int element;
        printf("Given array :\n");
        for (i=0;i<n;i++){
                printf("%d ",arr[i]);
        }
        
        printf("\nenter the element you want to enter: ");
        scanf("%d", &element);
        printf("Enter the position : ");
        scanf("%d",&index);
        index=index-1;
        if( n >= capacity){
                return -1;
        }

        for(i=n-1; i>=index; i--){
                arr[i+1] = arr[i];
        }
        arr[index] = element;
        n++;

        printf("the required array is: ");

        for(i=0; i<n; i++){
                printf("%d ", arr[i], " ");
        }
        printf("\n");
        return 0;
}