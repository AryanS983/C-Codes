#include <stdio.h>
int main () {
    int s;
    for (s=0;s<=10;s++){
        printf("HEllo");
        if (s==5)
        continue;
        printf(" %d ",s);
    }
    return 0;
}

// #include <stdio.h>
// int main () {
//     int num,sum=1;
//     lol:
//     printf("Enter a Number from 1 to 1000(999 to end)");
//     scanf("%d", &num );
//     if (num!=999){
//         if (num<0)
//             goto lol;
//         sum+=num;
//         goto lol;    
//     }
//     printf("%d",sum);
//     return 0;
// }