// C code to linearly search x in arr[].

#include <stdio.h>


int main()
{
	int arr[] = { 24, 65, 78, 29, 80 };
	int x ,i,found=-1;
	int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array: \n");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nElement to be searched : "); scanf("%d",&x);
    for (i=0;i<n;i++){
        if (arr[i]==x){
            found=i;break;
        }
    }
	
	if(found!=-1) {
        printf("Element is present at index %d", found);
	
    }
    else{
         printf("Element is not present in array");
    }
		
	return 0;
}