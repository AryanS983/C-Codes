#include <stdio.h>
int func1(int a, int b);
// void func2(int a);
int func3();
void func4();
void func5(int *b);
int main() {
    int c,b,x;
    c=func1(9,4);
    printf("%d\n",c);
    scanf("%d",&b);
    // func2(b);
    x=func3();
    printf("\n%d\n",x);
    func4();
    printf("%d\n",b);
    func5(&b);
    
    return 0;
}
int func1(int a, int b){
    return a+b;             //with argument and return value
}
// void func2(int a){
//     int i;                      //with argument without return value
//     for (i=0;i<a;i++){
//         printf("%c",'*');
//     }
// }
int func3(){
    int b=7;                //witout argument with return value
    return b;

}
void func4() {
    int b=10;               //without argument anf return value
    printf("%d\n",b);
}
void func5(int *num){
    *num=*num+2;                //call by reference
    printf("%d",*num);
}