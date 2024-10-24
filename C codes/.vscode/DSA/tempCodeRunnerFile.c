#include <stdio.h>
struct node {
    int key;
    struct node* next;
};
int main(){
    // int left=1 ,right =1;
    // printf("%d",left>right? left:right+1);
    struct node* root;
    root->key=10;
    root->next=NULL;
    printf("%d",root? 1:2);
    return 0;
}