#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"

int main()
{
    Node *root = createNode(3);

    root = insertNode(root, 1); // cria uma cópia da árvore atualizada e reatribui
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);

    preorder(root);

    freeTree(root);

    return 0;
}