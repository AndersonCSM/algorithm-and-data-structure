#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void process(Node *node)
{
    printf("%d ", node->data);
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        process(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void order(Node *root)
{
    if (root != NULL)
    {
        order(root->left);
        process(root);
        order(root->right);
    }
}

void posorder(Node *root)
{
    if (root != NULL)
    {
        posorder(root->left);
        posorder(root->right);
        process(root);
    }
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(5);

    root->right->left = createNode(12);
    root->right->right = createNode(18);

    printf("\nPre-ordem:\n");
    preorder(root);

    printf("\nOrdem:\n");
    order(root);

    printf("\nPos-ordem:\n");
    posorder(root);
}