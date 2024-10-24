#include <stdio.h>
void print(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void insert(int arr[], int pos, int element,int n){
    int i;
    for (i=n;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[i]=element;
}

int main(){
    int arr1[10]={12,10,25,40,75};
    int i,j,k=0,pos,element;
    int n=5;
    printf("%d",j);
    printf("Innitial array:\n");
    print(arr1,n);
    printf("\n new element to be inserted:"); scanf("%d",&element);
    printf("\n Enter its position: "); scanf("%d", &pos);
    for (i=n;i>=pos;i--){
        arr1[i+1]=arr1[i];
    }
    arr1[i]=element;
    print(arr1,n+1);
    return 0;
}