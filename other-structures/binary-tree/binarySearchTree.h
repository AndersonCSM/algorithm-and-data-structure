#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data);
void process(Node *node);
void preorder(Node *root);
void order(Node *root);
void posorder(Node *root);
Node *insertNode(Node *node, int key);
Node *insertNode(Node *node, int key);
Node *searchNode(Node *root, int key);
Node *removeNode(Node *root, int x);
Node *getMin(Node *node);
Node *getMax(Node *node);
Node *getSucessor(Node *node);
Node *getAntecessor(Node *node);
Node *freeTree(Node *root);

#endif