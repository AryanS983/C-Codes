// #include <stdio.h>
// int main() {
//     int i,j;
//     for (i=1;i<=5;i++){
//         for (j=1;j<=5;j++){
//             if (i==1 || i==5 || j==1 || j==5)
//             printf("*");
//             else 
//             printf(" ");
//         }
//         printf("\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// int main () {
//     int i,j;
//     for (i=1;i<=5;i++){
//         for (j=1; j<=i;j++){
//             printf ("*");
//         }
//         printf ("\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// int main () {
//     int i,j;
//     for (i=1;i<=5;i++){
//         for (j=5; j>=i;j--){
//             printf ("*");
//         }
//         printf ("\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// int main () {
//     int i,j,k;
//     for (i=1;i<=5;i++){
//         for(k=1;k<i;k++){
//             printf(" ");
//         }
//         for (j=5; j>=i;j--){
//             printf ("*");
//         }
//         printf ("\n");
//     }
//     return 0;
// }


#include <stdio.h>
int main () {
    int i,j,k,l;
    for (i=1;i<=5;i++){
        for(k=5;k>i;k--){
            printf(" ");
        }
        for (j=1; j<=i;j++){
        
            printf ("*");
        
        }
        printf ("\n");
    }
    return 0;
}
