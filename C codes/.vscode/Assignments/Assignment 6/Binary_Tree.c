#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define a structure for a stack to help with non-recursive traversal
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = *top;
    *top = stackNode;
}

// Function to check if the stack is empty
bool isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        return NULL;
    }
    struct TreeNode* node = (*top)->node;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;
}

// Function for non-recursive preorder traversal
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    push(&stack, root);
    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(&stack);
        printf("%d ", node->data);
        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

// Function for non-recursive inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;
    while (!isEmpty(stack) || current != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function for non-recursive postorder traversal
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct TreeNode* node = pop(&stack1);
        push(&stack2, node);
        if (node->left) push(&stack1, node->left);
        if (node->right) push(&stack1, node->right);
    }
    while (!isEmpty(stack2)) {
        struct TreeNode* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}
