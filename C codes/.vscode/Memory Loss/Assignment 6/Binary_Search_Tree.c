#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int key){
    struct node* new=malloc(sizeof(struct node));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void insert(struct node* root, int key){
    struct node* temp;
    while(root!=NULL){
        temp=root;
        if(key==root->data){
            printf("Not Repetitions Allowed");
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new = createnode(key);
    if(key<temp->data){
        temp->left=new;
    }
    else{
        temp->right=new;
    }
}

// Easy insertion using recursion
struct node* insert2(struct node* root,int key){
    if(root==NULL){
        return createnode(key);
    }
    else if (key==root->data){
        printf("Key already exists");
        exit(1);
    }
    else if (key<root->data){
        root->left=insert2(root->left,key);
    }
    else{
        root->right=insert2(root->right,key);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main (){
    struct node* root=NULL;
    root=insert2(root,0);
    insert(root,3);
    insert(root,6);
    insert(root,1);
    insert(root,4);
    insert(root,16);
    insert2(root,17);
    // insert(root,2);
    // insert(root,3);
    // insert(root,4);
    // insert(root,5);
    // insert(root,6);
    // insert(root,7);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}