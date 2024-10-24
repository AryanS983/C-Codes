#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100 

int stack[max];
int top=-1;

int pop(){
    if(top==-1){
        printf("Underflow");
        exit(1);
    }
    return stack[top--];
}

void push(int item){
    if(top<max){
        stack[++top]=item;
    }
    else{
        printf("overflow");
        exit(1);
    }
}

int posteval(char postfix[]){
    int i=0;
    int n3;
    while(postfix[i]!='\0'){
        if(isdigit(postfix[i])){
            int a=postfix[i]-'0';
            push(a);
        }
        else{
            int n1=pop(),n2=pop();
            switch(postfix[i]){
                case '+':
                    n3=n2+n1; break;
                case '-':
                    n3=n2-n1; break;
                case '*':
                    n3=n2*n1; break;
                case '/':
                    n3=n2/n1; break;
            }
            push(n3);
        }
        i++;
    }
    return pop();
}

int main(){
    char postfix[max]="56+64-*";
    printf("%d", posteval(postfix));
    return 0;
}

