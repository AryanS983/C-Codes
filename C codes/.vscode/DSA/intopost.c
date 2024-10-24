#include <stdio.h>
#include <ctype.h>
typedef struct {
    char stack[100];
    int top;
}stack;

void push(stack *s, char val){
    s->stack[++s->top]=val;
}

char pop(stack*s){
    return s->stack[s->top--];
}

int precedence(char opr){
    switch (opr){
        case '^': return 3;break;
        case '*':
        case '/': return 2; break;
        case '+':
        case '-': return 1; break;
        default : return 0;
    }
}

int main (){
    char infix[20], postfix[20];
    stack operator;
    operator.top=-1;
    printf("Enter infix: ");
    scanf("%s", infix);
    int postindex=0;
    for (int i=0; infix[i]!='\0'; i++){
        if(isalnum(infix[i])){
            postfix[postindex++]=infix[i];
        }
        else if(infix[i]=='('){
            push (&operator, infix[i]);
        }
        else if(infix[i]==')'){
            while (operator.stack[operator.top]!='('&& operator.top!=-1){
                int opr=pop(&operator);
                postfix[postindex++]=opr;
            }
            pop(&operator);
        }
        else{
            while(precedence(operator.stack[operator.top])>=precedence(infix[i])){
                postfix[postindex++]=pop(&operator);
            }
            push(&operator, infix[i]);
        }
    }
    while (operator.top!=-1){
        postfix[postindex++]=pop(&operator);
    }
    postfix[postindex]='\0';
    printf("\nPostfix: %s",postfix);
    return 0;
}
