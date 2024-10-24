#include <stdio.h>
int main() {
    int x;
    scanf("%d",&x);
    if (x==0)
    return 0;
    else if (x%2==0)
    printf("EVEN");
    else 
    printf("ODD");
    return 0;
}