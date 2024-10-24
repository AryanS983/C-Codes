#include <stdio.h>
#include <stdlib.h>
#define max 100

int queue[max];
int rear=-1;
int front=-1;

void priority(int data);

int isEmpty(){
    return front==-1;
}
void enqueue(int data){
    if (rear>=max){
        printf("Overflow");
        return;
    }
    else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=data;
    }
    priority(data);
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow");
        exit(1);
    }
    else{
        // int deq = queue[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
}

void priority(int data){
    int i=rear-1;
    if(isEmpty()){
        return;
    }
    else{
        for(i=rear-1;i>=front && queue[i]>=data;i--){
            queue[i+1]=queue[i];
        }
        queue[i+1]=data;
    }
}

void display(){
    int i;
    if(front!=-1){
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        printf("Underflow");
    }
}

int main(){
    enqueue(5);
    enqueue(7);
    enqueue(3);
    enqueue(1);
    enqueue(12);
    dequeue();
    display();
    return 0;
}