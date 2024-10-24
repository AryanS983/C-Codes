#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPRESSION_SIZE 100

typedef struct {
    char stack[MAX_EXPRESSION_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX_EXPRESSION_SIZE - 1) {
        s->stack[++s->top] = value;
    } 
    else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int getPrecedence(char operator) {
    switch (operator) {
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

void infixToPostfix(char *infix, char *postfix) {
    Stack operatorStack;
    initialize(&operatorStack);

    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[postfixIndex++] = infix[i];
        } else if (infix[i] == '(') {
            push(&operatorStack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.stack[operatorStack.top] != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop '(' from stack
        } else {
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.stack[operatorStack.top]) >= getPrecedence(infix[i])) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infixExpression[50];
    char postfixExpression[MAX_EXPRESSION_SIZE];
    printf("Enter the infix expression : ");
    scanf("%s", &infixExpression);
    infixToPostfix(infixExpression, postfixExpression);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    return 0;
}
