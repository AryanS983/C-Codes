#include <stdio.h>
#include <stdlib.h>

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

void DFS(int i){
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<7;j++){
        if(arr[i][j] && visited[j]==0){
            DFS(j);
        }
    }
}

int main(){
    DFS(0);
    return 0;
}