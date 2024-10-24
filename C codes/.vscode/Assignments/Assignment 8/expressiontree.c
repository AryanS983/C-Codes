#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


struct TreeNode* buildExpressionTree(char postfix[]) {
    int length = strlen(postfix);
    struct TreeNode* stack[length];
    int top = -1;

    for (int i = 0; i < length; i++) {
        char symbol = postfix[i];

        if (!isOperator(symbol)) {
            struct TreeNode* operandNode = createNode(symbol);
            stack[++top] = operandNode;
        } else {

            struct TreeNode* rightOperand = stack[top--];
            struct TreeNode* leftOperand = stack[top--];


            struct TreeNode* operatorNode = createNode(symbol);
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;


            stack[++top] = operatorNode;
        }
    }


    return stack[top];
}


void printInfix(struct TreeNode* root) {
    if (root) {
        if (isOperator(root->data))
            printf("(");
        
        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);

        if (isOperator(root->data))
            printf(")");
    }
}

int main() {
    char postfix[] = "ab+ef*g*-";
    struct TreeNode* root = buildExpressionTree(postfix);

    printf("Infix Expression: ");
    printInfix(root);
    printf("\n");

    return 0;
}