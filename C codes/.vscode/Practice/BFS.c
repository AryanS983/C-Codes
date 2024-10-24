#include <stdio.h>
#include <stdlib.h>
#define max 100

int Exp[max];
int front=-1;
int rear=-1;

int isEmpty(){
    return front==-1;
}

int isFull(){
    return rear>max;
}

void enqueue(int item){
    if(isFull()){
        printf("Overflow");
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        Exp[rear]=item;
    }
}

int dequeue(){
    if(isEmpty()){
        printf("Underflow");
        exit(1);
    }
    else{
        int deq = Exp[front];
        if(front==rear){
            front=rear=-1;
        }
        else
            front++;
        return deq;
    }
}

int main(){
    
    int visited[7]={0,0,0,0,0,0,0};
    int arr[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,0,1,0,0},
        {1,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    int i=0,j;
    printf("%d",i);
    visited[i]=1;
    enqueue(i);
    
    while(!isEmpty()){
        int node=dequeue();
        for(j=0;j<7;j++){
            if(arr[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
    return 0;
}