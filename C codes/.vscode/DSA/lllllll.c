#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head=NULL;

struct node* create (int data){
    head = (struct node*) malloc (sizeof(struct node));
    head->data=data;
    head->next=NULL;
    return head;
}

void insertbeginning(int data){
    if (head==NULL){
        head=create(data);
    }
    else{
        struct node* ptr=malloc(sizeof (struct node));
        ptr->data=data;
        ptr->next=head;
        head=ptr;
    }
    
}

void insertend(int data){
    struct node* ptr=head;
    struct node* ptr1=malloc(sizeof(struct node));
    ptr1->data=data;
    ptr1->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr1;
}

void display(){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void reverse(){
    struct node* current=head;
    struct node* prev=NULL;
    struct node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

int main(){
    insertbeginning(30);
    insertbeginning(25);
    insertend(10);
    insertend(45);
    display();
    reverse();
    display();
}
