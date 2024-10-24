#include <stdio.h>
int main () {
    int a=9;
    int* ptr = &a;
    typedef int* point;
    point b,*c;
    b=&a;
    c=&ptr;
    printf("%d %d %d %d\n",a,ptr, &ptr, (int)sizeof(ptr));
    printf ("%d %d %d",b,c,**c);
    
    return 0;
}