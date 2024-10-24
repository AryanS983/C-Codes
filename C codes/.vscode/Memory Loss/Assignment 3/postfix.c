#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 50

int stack[max];
int top=-1;

void push(int value){
    stack[++top]=value;
}

int pop(){
    return stack[top--];
}

int main(){
    char exp[max];
    char  *e;
    int n1, n2, n3, num;
    printf("Enter postfix expression: "); scanf("%s", &exp);
    e=exp;
    while (*e != '\0'){
        if(isdigit(*e)){
            num=*e-'0';
            push(num);
        }
        else{
            n1=pop();
            n2=pop();
            switch(*e){
                case '+':
                {
                    n3=n2+n1; break;
                }
                case '-':
                {
                    n3=n2-n1; break;
                }
                case '*':
                {
                    n3=n2*n1; break;
                }
                case '/':
                {
                    n3=n2/n1; break;
                }
            }
            push(n3);
        }
        e++;
    }
    printf("Evaluated Expression: %d",pop());
    return 0;
}
