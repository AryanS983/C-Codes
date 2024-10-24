#include <stdio.h>
#include <stdlib.h>
#define max 10

int queue [max];
int rear=-1;
int front=-1;
void enqueue(int val) {
    if(rear==max-1){
        printf("Ma chudao queue Overflow");
        exit(1);
    }
    else{
        queue[++rear]=val;
    }
    printf("%d Enqueued in the queue\n",val);
}

void dequeue(){
    if (rear==-1){
        printf("Choti lulii wale apna size badha le matlab queue chota hai");
        exit(1);
    }
    else{
        if(front==rear){
            front=rear=-1;
            printf("Choti lulii wale apna size badha le matlab queue chota hai");
        }
        else{
            printf("%d Dequeued from the queue\n", queue[front+1]);
            front++;
        }
    }
}

void display(){
    if(rear==-1){
        printf("Lauda kuch nhi hai dikhane ko");
    }
    else{
        int i;
        printf("Queue: \n");
        for(i=front+1;i<=rear;i++){
            printf("%d,",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int i,choice,val;
    while(1){
        printf("Queue Menu:\n");
        printf("1) Enqueue\n 2) Dequeue\n 3) Display\n 4) Exit\n");
        printf("Your Choice: "); scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter the Element to be enqueued: "); scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Input");
                break;
        }
    }
    return 0;
}

