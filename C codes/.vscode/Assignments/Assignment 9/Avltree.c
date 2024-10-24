#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to calculate the height of a node
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the balance factor of a node
int balanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to update the height of a node
void updateHeight(Node* node) {
    if (node == NULL)
        return;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    updateHeight(root);

    int balance = balanceFactor(root);

    // Left Heavy
    if (balance > 1) {
        if (key < root->left->key) {
            // Left-Left Case
            return rightRotate(root);
        } else {
            // Left-Right Case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (key > root->right->key) {
            // Right-Right Case
            return leftRotate(root);
        } else {
            // Right-Left Case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to find the node with the minimum key value in the tree
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a key from the AVL tree
Node* delete(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    int balance = balanceFactor(root);

    // Left Heavy
    if (balance > 1) {
        if (balanceFactor(root->left) >= 0) {
            // Left-Left Case
            return rightRotate(root);
        } else {
            // Left-Right Case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (balanceFactor(root->right) <= 0) {
            // Right-Right Case
            return leftRotate(root);
        } else {
            // Right-Left Case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to search for a key in the AVL tree
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

// Function to perform an in-order traversal of the tree
void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("AVL Tree Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. In-order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
