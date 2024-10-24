#include <stdio.h>
void func1(int x){
    printf("%d", x);
}
int func2(int x){
    printf("%d", x);
    return x;
}

int main () {
    int y,i=10;
    func1(i);
    y=func2(i);
    printf("\n%d",y);
    
    
}