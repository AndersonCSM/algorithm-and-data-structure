#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree/binarySearchTree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};

    Node *tree = createTree(list1, 7, ITER);

    traverse(tree, IN, printNode);

    freeTree(tree);

    return 0;
}