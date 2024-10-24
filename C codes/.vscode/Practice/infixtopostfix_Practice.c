#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

int stack[max];
int top=-1;

int isEmpty(){
    return top==-1;
}

int pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    else{
        printf("Underflow");
        exit(1);
    }
}

void push(int item){
    if(top<max-1){
        stack[++top]=item;
    }
    else{
        printf("Overflow");
        exit(1);
    }
}

int precedence(char operator){
    switch(operator){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void intopost(char infix[],char postfix[]){
    int i;
    int postindex=0;
    for (i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[postindex++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!isEmpty() && stack[top]!='('){
                postfix[postindex++]=pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && precedence(stack[top])>precedence(infix[i]) ){
                postfix[postindex++]=pop();
            }
            push(infix[i]);
        }
    }
    while(!isEmpty()){
        postfix[postindex++]=pop();
    }
    postfix[postindex]='\0';
}

int main(){
    char infix[]= "(a+b)*(c-d)";
    char postfix[max];
    intopost(infix,postfix);
    printf("%s", postfix);
    return 0;
}