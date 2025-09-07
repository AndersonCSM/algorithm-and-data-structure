#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree/binarySearchTree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};

    Node *tree = createTree(list1, 7);

    printf("\nArvore antes: \n");
    preorder(tree);
    printf("\nArvore apos remover o menor:\n");
    tree = removeMin(tree);
    preorder(tree);

    freeTree(tree);

    return 0;
}