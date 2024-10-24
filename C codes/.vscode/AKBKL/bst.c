#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchld;
    struct node *rchld;
};
struct node *root;
void init_bst(struct node *);
struct node *rsearch(int, struct node *);
struct node *isearch(int, struct node *);
void insert(int);
void print(struct node *); // inorder traversal
int main(void)
{ // BST
    int data;
    root = NULL;
    while (scanf("%d", &data))
        insert(data);
    rsearch(36, root);
    printf("\n");
    print(root);
    return 0;
}

void init_bst(struct node *r) { r = NULL; }

struct node *rsearch(int x, struct node *r)
{
    if (!r)
    {
        printf("NOT FOUND");
        return NULL;
    }
    if (x == r->data)
        return r;
    if (x < r->data)
        return rsearch(x, r->lchld);
    return rsearch(x, r->rchld);
}

struct node *isearch(int x, struct node *r)
{
    struct node *p;
    p = r;
    while (p)
    {
        if (x == p->data)
            return p;
        if (x < p->data)
            p = p->lchld;
        else
            p = p->rchld;
    }
    return NULL;
}

void insert(int x)
{
    struct node *c, *q, *p;
    q = (struct node *)malloc(sizeof(struct node));
    q->data = x;
    q->lchld = NULL;
    q->rchld = NULL;
    if (root == NULL)
    {
        root = q;
    }
    else
    {
        c = root;
        p = NULL;
        while (1)
        {
            p = c;
            if (x < p->data)
            {
                c = c->lchld;
                if (c == NULL)
                {
                    p->lchld = q;
                    return;
                }
            }
            else
            {
                c = c->rchld;
                if (c == NULL)
                {
                    p->rchld = q;
                    return;
                }
            }
        }
    }
}

void print(struct node *node)
{ // inorder traversal
    if (node == NULL)
        return;
    print(node->lchld);
    printf("->%d", node->data);
    print(node->rchld);
}