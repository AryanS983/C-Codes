#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 50

char stack[max];
int top;

int isEmpty(){
    return (top==-1);
}

char pop(){
    if (!isEmpty()){
        return stack[top--];
    }
    else{
        printf("Underflow");
        exit(1);
    }
}

void push(char element){
    if(top<max-1){
        stack[++top]=element;
    }
    else{
        printf("Overflow");
        exit(1);
    }
}

int precedence(char operator){
    switch(operator){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixtopostfix(char infix[], char postfix[]){
    int i=0;
    int postindex=0;
    while(infix[i]!='\0'){
        if (isalnum(infix[i])){
            postfix[postindex++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(stack[top]!='(' && !isEmpty()){
                postfix[postindex++]=pop();
            }
            pop();
        }
        else {
            while(!isEmpty() && precedence(stack[top])>=precedence(infix[i])){
                postfix[postindex++]=pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while(!isEmpty()){
        postfix[postindex++]=pop();
    }

    postfix[postindex]='\0';
}

int main(){
    top=-1;
    char infix[max];
    char postfix[max];
    printf("Infix Expression: "); scanf("%s", &infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression: %s", postfix);
    return 0;
}