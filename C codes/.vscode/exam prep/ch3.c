#include <stdio.h>
#include <string.h>
int main () {
    // char arr[5]= "920";
    // static int num;
    // num= atoi(arr);
    char arr1[]= "ram";
    char arr2[] = "Ram";
    printf("%d",strcmp (arr1,arr2));
    if (strcmp(arr1, arr2)){
        printf("ram is Ram");
    }
    int a=10;           //function scope
    int i=0;
    while (i<3){
        int a=i;            //block scope
        printf("%d ",a);
        i++;
    }
    printf("%d ", a);

    
    // printf("%d", num);
    return 0;
}