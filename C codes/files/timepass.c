// #include<stdio.h>
// int main()  {
//     int i, arr[15];
//     for(i=0;i<9;i++) {
//         scanf("%d", &arr[i]);
//     }
//     for(i=0;i<9;i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

#include<stdio.h>
void insert (int arr[20], int ub, int pos, int val){
    int i ;
    for (i=ub; i>=pos; i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;

}
int main()  {
    int i,A[20]={3,4,5,8,9};
    insert (A,4,2,7);
    for (i=0;i<6; i++){

        printf("%d ",A[i]);
    }
    return 0;

}