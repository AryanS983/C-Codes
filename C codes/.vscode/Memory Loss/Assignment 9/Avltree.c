#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height; 
};

int max(int a, int b){
    return (a>b)?a:b;
}

struct node* createnode(int key){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

int getheight(struct node* node){
    if (node==NULL)
        return 0;
    return (node->height);
}

int balancefactor(struct node* node){
    if (node==NULL){
        return 0;
    }
    return getheight(node->left)-getheight(node->right);
}

struct node* rightrotation(struct node* y){
    struct node* x= y->left;
    struct node* T2= x->right;

    x->right=y;
    y->left=T2;

    x->height= 1 + max(getheight(x->left),getheight(x->right));
    y->height= 1 + max(getheight(y->left),getheight(y->right));
    return x;
}
struct node* leftrotation(struct node* x){
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left=x;
    x->right=T2;

    x->height= 1 + max(getheight(x->left),getheight(x->right));
    y->height= 1 + max(getheight(y->left),getheight(y->right));
    return y;
}

struct node* insert(struct node* root,int key){
    if (root==NULL){
        return createnode(key);
    }
    else if (key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }

    root->height = 1 + max(getheight(root->left),getheight(root->right));
    
    int bf=balancefactor(root);

    //left left  case
    if (bf>1 && key<root->left->data){
        root= rightrotation(root);
    }
    //right right case
    if (bf<-1 && key>root->right->data){
        root= leftrotation(root);
    }
    //left right case
    if (bf>1 && key>root->left->data){
        root->left=leftrotation(root->left);
        root= rightrotation(root);
    }
    //right left case
    if (bf<-1 && key<root->right->data){
        root->right=rightrotation(root->right);
        root= leftrotation(root);
    }
    return root;
}

void infix(struct node* root){
    if (root!=NULL){
        infix(root->left);
        printf("%d ",root->data);
        infix(root->right);
    }
}

int main(){
    struct node* root=NULL;
    // root=createnode(10);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
root=insert(root,7);
    infix(root);
    return 0;
}
