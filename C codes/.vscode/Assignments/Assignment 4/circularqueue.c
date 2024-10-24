#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull()) {
                    printf("Enter element to enqueue: ");
                    scanf("%d", &item);
                    enqueue(item);
                } else {
                    printf("Queue is full. Cannot enqueue.\n");
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
