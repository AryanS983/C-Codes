#include <stdio.h>
#include <stdlib.h>
#define MAX 50

float average(int *ptr, int n){
    int i, sum=0 ;
    float avg;
    if (n<=0){
        printf("FUCK OFF");
        exit(1);
    }
    else {
        for (i=0;i<n; i++){
            sum+=(*ptr);
            ptr++;
        }
    }
    avg= sum/n;
    return avg;

    
}

int main (){
    int  *parr, n,i ;
    int nums[MAX]= {20,30,50,40,10};
    n=5;
    parr= nums;
    printf("%.2f",average (parr, n) );
    return 0;

}

