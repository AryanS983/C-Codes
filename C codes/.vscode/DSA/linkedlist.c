#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};



struct Node* insertfirst (struct Node* head ,int num){
    struct Node *ptr2;
    ptr2=(struct Node *)malloc(sizeof(struct Node));
    ptr2->data=num;
    ptr2->next=head;
    return ptr2;
}

struct Node* insertbetween(struct Node* head, int index,int value){
    struct Node* p;
    p=head;
    for (int i=0; i<index-1; i++){
        p=p->next;
    }
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertend(struct Node* head,int element){
    struct Node* p;
    p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=element;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node* insertafternode(struct Node* head, struct Node* previousNode, int element){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* next;
    ptr->data=element;
    ptr->next=previousNode->next;
    previousNode->next=ptr;
    return head;
}

struct Node* delend(struct Node* head){
    struct Node* p=head, *q;
    while(p->next->next!=NULL){
        p=p->next;
    }
    q=p->next;
    p->next=NULL;
    free(q);
    return head;
}

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    // struct Node *head;
    // struct Node *second;
    // struct Node *third;
    // struct Node *fourth;
 
    // // Allocate memory for nodes in the linked list in Heap
    
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // // Link first and second nodes
    // head->data = 7;
    // head->next = second;
 
    // // Link second and third nodes
    // second->data = 11;
    // second->next = third;
 
    // // Link third and fourth nodes
    // third->data = 41;
    // third->next = fourth;
 
    // // Terminate the list at the third node
    // fourth->data = 66;
    // fourth->next = NULL;

    int n, index;
    struct Node* head;
    struct Node* p;
    struct Node *second;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
   
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = NULL;
    printf("Enter the element to be inserted at the beginning: "); scanf("%d",&n);
    head=insertfirst(head,n);
    linkedListTraversal(head);
    printf("Enter the element to be inserted in between : "); scanf("%d",&n);
    printf("Enter the index: "); scanf("%d", &index);
    head=insertbetween(head,index,n);
    linkedListTraversal(head);
    printf("Enter the element to be inserted at the end  : "); scanf("%d",&n);
    head=insertend(head,n);
    linkedListTraversal(head);
    printf("Enter the element to be inserted and after how many numbers: ");  scanf("%d %d",&n,&index);
    p=head;
    for(int i=0 ;i<index-1 ;i++ ){
        p=p->next;
    }
    head=insertafternode(head,p,n);
    linkedListTraversal(head);
    
    printf("After deletion of last elemment:- \n");
    head=delend(head);
    linkedListTraversal(head);


    return 0;
}