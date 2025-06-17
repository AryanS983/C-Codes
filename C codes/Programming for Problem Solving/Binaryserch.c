#include<stdio.h>
#include <stdlib.h>
#define MAX     100

int bSearch(int*arr,int n,int val,int*pos)
{
int left=0 ,right=n-1,mid;
int passes=0;
    while (left<=right){
    passes++;
    mid=(left+right)/2;
    if(arr[mid]==val){
    *pos=val;
    return passes;
    }
        else if(arr[mid]<val){
            left=mid+1;
        }
        else {
            right=mid-1;
            }
            
    }
    *pos=-1;
    return passes;
        
       
}


int main()
{
    int arr[MAX], pos, n, val, passes;

    // Enter size
    scanf("%d",&n);
    if(n==0){
        printf("ERROR:Empty List");
        exit(0);
    }

    // Enter elements
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // Enter element to be searched
    scanf("%d",&val);

    passes = bSearch(arr, n, val, &pos);
    printf("%d found at index: %d. Number of passes: %d", val, pos, passes);

    return 0;
}