#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isEmpty(struct Node* head){
    return (head==NULL);
}

struct Node* push(struct Node* head, int val){
    if (isEmpty(head)){
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=val;
        head->next=NULL;
    }
    else{
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=val;
        ptr->next=head;
        head=ptr;
    }
    return head;
}

struct Node* pop(struct Node* head){
    if (isEmpty(head)){
        printf("Stack is Empty!!! Deletion is not possible!!!");
        exit(1);
    }
    else{
        struct Node* temp = head;
        head=head->next;
        free(temp);
    }
    return head;
}

void display(struct Node* head){
    if(isEmpty(head)){
        printf("Stack is Empty!!!");
        exit(1);
    }
    else{
        struct Node* temp=head;
        printf("Elements of Stack: ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("\n"); 
    }
}

int main(){
    struct Node* head=NULL;
    int choice,temp;
    while(1){
        printf("\nStack Operations using Linked List\n");
        printf("Select option:\n 1) push\n 2) pop\n 3) display\n 4) Exit\n");
        printf("Your Choice: ");scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the value to be pushed into the stack: ");scanf("%d", &temp);
            head=push(head,temp);
            printf("%d pushed into the stack.\n",temp);
            break;
        case 2:
            if(!isEmpty(head)){
                printf("%d is deleted from the stack.\n", head->data);
            }
            head=pop(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Enter a valid input.\n");
        }
    }
    return 0;
}

