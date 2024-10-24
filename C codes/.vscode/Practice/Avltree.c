#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createnode(int key){
    struct node* new=malloc(sizeof(struct node));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int max(int a, int b){
    return a>b? a:b;
}

int getheight(struct node* node){
    if (node==NULL)
        return 0;
    return node->height;
}

int balancefactor(struct node* node){
    if (node==NULL)
        return 0;
    return getheight(node->left)-getheight(node->right);
}

struct node* rightrotation(struct node* y){
    struct node* x = y->left;
    struct node* t2 = x->right;
    x->right=y;
    y->left=t2;

    y->height= 1+max(getheight(y->left),getheight(y->right));
    x->height= 1+max(getheight(x->left),getheight(x->right));
    return x;
}

struct node* leftrotation(struct node* x){
    struct node* y = x->right;
    struct node* t2 = y->left;
    y->left=x;
    x->right=t2;
    x->height= 1+max(getheight(x->left),getheight(x->right));
    y->height= 1+max(getheight(y->left),getheight(y->right));
    return y;
}

struct node* insert(struct node* node,int key){
    if(node==NULL){
        return createnode(key);
    }
    else if(key<node->data){
        node->left=insert(node->left,key);
    }
    else{
        node->right=insert(node->right,key);
    }

    node->height= 1+max(getheight(node->left),getheight(node->right));

    int bf=balancefactor(node);

    if (bf>1 && key<node->left->data){
        node=rightrotation(node);
    }
    if (bf<-1 && key>node->right->data){
        node=leftrotation(node);
    }
    if(bf>1 && key>node->left->data){
        node->left=leftrotation(node);
        node=rightrotation(node);
    }

    if(bf<-1 && key<node->right->data){
        node->right=leftrotation(node->right);
        node=leftrotation(node);
    }

    return node;
}

void inorder (struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}
void preorder (struct node* root){
    if(root!=NULL){
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    // inorder(root);
    preorder(root);
    return 0;
}