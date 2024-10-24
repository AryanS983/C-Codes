#include <stdio.h>
#define MAX(a,b) a>b?a:b  
int main () {
    unsigned int x=100;
    int y=-100;
    int z = y++;
    if (x>y){
        printf("100>-100");
    }
    else 
        printf("fuck you");
    // printf ("%d%d%u%u", x,y,(int)y,x);
    // printf ("%d", z);
    // z=y++;
    // printf ("%d", z);

    printf("%d", MAX(y,z));
    int p=10;
    printf(" %d %d %d",p, ++p,p++);
    return 0;
}