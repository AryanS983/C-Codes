#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to calculate the sum of nodes at odd levels
int getOddLevelSum(struct Node* root, int level) {
    if (root == NULL) {
        return 0;
    }

    if (level % 2 != 0) {
        return root->data + getOddLevelSum(root->left, level + 1) + getOddLevelSum(root->right, level + 1);
    } else {
        return getOddLevelSum(root->left, level + 1) + getOddLevelSum(root->right, level + 1);
    }
}

// Function to calculate the sum of nodes at even levels
int getEvenLevelSum(struct Node* root, int level) {
    if (root == NULL) {
        return 0;
    }

    if (level % 2 == 0) {
        return root->data + getEvenLevelSum(root->left, level + 1) + getEvenLevelSum(root->right, level + 1);
    } else {
        return getEvenLevelSum(root->left, level + 1) + getEvenLevelSum(root->right, level + 1);
    }
}

// Function to calculate the difference between the sum of odd and even level nodes
int getLevelDifference(struct Node* root) {
    int oddSum = getOddLevelSum(root, 1);
    int evenSum = getEvenLevelSum(root, 1);
    return oddSum - evenSum;
}

int main() {
    // Example binary search tree
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    // Calculate and print the difference between the sum of odd and even level nodes
    int difference = getLevelDifference(root);
    printf("Difference between the sum of odd and even level nodes: %d\n", difference);

    return 0;
}