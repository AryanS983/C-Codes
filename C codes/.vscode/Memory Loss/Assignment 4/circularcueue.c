#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue [max];
int rear=-1;
int front=-1;

int isFull(){
    return front==(rear+1)%max;
}

void enqueue(int val) {
    if(isFull()){
        printf("Not enoough space\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%max;
        queue[rear]=val;
        printf("%d Enqueued\n",val);
    }
}

void dequeue(){
    if(front==-1){
        printf("khaali queue");
    }
    else{
        printf("%d Dequeued\n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%max;
        }
    }
}

void display(){
    if(rear==-1){
        printf("Lauda kuch nhi hai dikhane ko\n");
    }
    else{
        int i=front;
        printf("Queue: \n");
        do{
            printf("%d,",queue[i]);
            i=(i+1)%max;
        }while(i<=rear);
        printf("\n");
    }
}

int main(){
    int i,choice,val;
    do{
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
    }while(1);
    return 0;
}

