#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node with data %d deleted.\n", data);
        return;
    }
    struct Node* prev = *head;
    struct Node* curr = (*head)->next;
    while (curr != NULL) {
        if (curr->data == data) {
            prev->next = curr->next;
            free(curr);
            printf("Node with data %d deleted.\n", data);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Node with data %d not found.\n", data);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to sort the linked list using bubble sort
void sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    int swapped;
    struct Node* temp;
    struct Node* end = NULL;

    do {
        swapped = 0;
        temp = *head;

        while (temp->next != end) {
            if (temp->data > temp->next->data) {
                int tmp = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tmp;
                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);

    display(head);

    deleteNode(&head, 10);
    deleteNode(&head, 30);

    display(head);

    reverse(&head);

    display(head);

    insertAtBeginning(&head, 50);
    insertAtEnd(&head, 5);

    display(head);

    sort(&head);

    display(head);

    return 0;
}