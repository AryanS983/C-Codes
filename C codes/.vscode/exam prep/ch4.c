#include <stdio.h>
int a=10;               //program scope
void print(){
    static int a;         //file scope
    printf("%d ", a);
    a++;
}
int main () {
    printf("%d ", a);
    int a=20;
    printf("%d ", a);
    print();
    printf("\n");
    print();
    printf("%d ", a);
    return 0;
} 