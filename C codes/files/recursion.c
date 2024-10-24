// #include <stdio.h>
// int x=10;
// void print ();
// int main () {
//     printf("%d",x);
//     int x=2;
//     printf("%d",x);
//     print();
//     print();
//     return 0;
// }

// void print (){
//     static int x=0;
//     printf("%d",++x);
// }
#include <stdio.h>
int fib(int num)
{
    if (num <2)
    {
        return num;
    }
    else
        return (fib(num - 1) + fib(num - 2));
}
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
    return 0;
}