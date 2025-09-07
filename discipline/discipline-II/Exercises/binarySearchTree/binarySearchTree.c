#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"

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

Node *insertNode(Node *node, int key) // tudo que é passado para uma função é uma cópia, nesse caso cópia de um endereço
{                                     // inserção recursiva
    if (!node)                        // onde ocorre a insercao se o nó estiver NULL/vazio
    {
        return createNode(key);
    }

    if (node->data == key) // evita duplicatas
    {
        return node;
    }

    if (node->data < key)
    {                                               // chave maior que o nó atual
        node->right = insertNode(node->right, key); // verifica na sub-direita com o novo nó sendo o da direita
    }
    else
    {                                             // só pode ser menor que o nó atual
        node->left = insertNode(node->left, key); // verifica na sub-esquerda com o novo nó sendo o da esquerda
    }

    return node; // retornar a árvore com a inserção realizada
}

Node *searchNode(Node *root, int key)      // tudo que é passado para uma função é uma cópia, nesse caso cópia de um endereço
{                                          // busca recursiva
    if (root == NULL || root->data == key) // se não achar root == NULL ou se achar root->data == key retorna o nó
    {
        return root;
    }

    if (root->data < key)
    {                                        // chave maior que o nó atual
        return searchNode(root->right, key); // busca agora pelo nó da direita
    }
    else
    {                                       // só pode ser menor que o nó atual
        return searchNode(root->left, key); // busca pelo nó da esquerda
    }
}

Node *getMax(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    while (node->right != NULL)
    {                       // enquanto não chegar na folha da direita: right == NULL
        node = node->right; // atualiza node pela direita
    }

    return node;
}

Node *getMin(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    while (node->left != NULL)
    {                      // enquanto não chegar na folha da esquerda: left == NULL
        node = node->left; // atualiza node pela esquerda
    }

    return node;
}

Node *getSucessor(Node *node)
{
    if (node == NULL || node->right == NULL)
    { // evita uma árvore sem sub-direita
        return NULL;
    }

    return getMin(node->right); // o sucessor é o menor da sub-direita do node
}

Node *getAntecessor(Node *node)
{
    if (node == NULL || node->left == NULL)
    { // evita uma árvore sem sub-esquerda
        return NULL;
    }

    return getMax(node->left); // o antecessor é o maior da sub-esquerda do node
}

Node *removeNode(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > x)
    { // busca pela direita
        root->left = removeNode(root->left, x);
    }
    else if (root->data < x)
    { // busca pela esquerda
        root->right = removeNode(root->right, x);
    }
    else
    { // nó igual ao valor buscado
        if (root->left == NULL)
        {                             // se ele não possuir filho a esquerda
            Node *temp = root->right; // repasso o ptr do filho da direita para a chamada recursiva
            free(root);               // removo o nó
            return temp;
        }
        if (root->right == NULL)
        {                            // se ele não possuir o filho a direita
            Node *temp = root->left; // repasso o ptr filho da direita para a chamada recursiva
            free(root);              // remove o nó
            return temp;
        }
        // se ele possuir os dois filhos
        Node *succ = getSucessor(root); // pega o sucessor do nó
        root->data = succ->data;        // atualiza o valor do nó para seu sucessor

        root->right = removeNode(root->right, succ->data); // remove o sucessor de maneira recursiva
    }
    return root;
}

void freeTree(Node *root)
{ // libera a árvore da memória usando percurso em pos-ordem
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

Node *createTree(int data[], int size)
{
    Node *root = NULL;

    for (int i = 0; i < size; i++)
    {
        root = insertNode(root, data[i]);
    }

    return root;
}

int getSize(Node *root)
{
    if (root != NULL)
    {
        int leftCount = getSize(root->left);
        int rightCount = getSize(root->right);

        return 1 + leftCount + rightCount; // o no atual mais os da sub-arvores
    }

    return 0;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return -1; // Convenção para árvore vazia
    }
    else
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Retorna 1 + a altura da maior sub-árvore
        if (leftHeight > rightHeight)
        {
            return 1 + leftHeight;
        }
        else
        {
            return 1 + rightHeight;
        }
    }
}

void ToArray(Node *root, int arr[], int *index)
{
    if (root == NULL)
    {
        return;
    }

    ToArray(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++; // Desreferencia e incrementa o índice para a próxima posição
    ToArray(root->right, arr, index);
}

float getMedian(Node *root)
{
    if (root == NULL)
    {
        return 0.0; // árvore vazia
    }

    int size = getSize(root);
    if (size == 0)
    {
        return 0.0;
    }

    // memoria para vetor auxiliar
    int *sortedArray = (int *)malloc(size * sizeof(int));
    if (sortedArray == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        return -1.0; // Indica erro
    }

    int index = 0;
    ToArray(root, sortedArray, &index);

    float median;
    if (size % 2 != 0) // Se for ímpar, a mediana é o elemento do meio
    {

        median = (float)sortedArray[size / 2];
    }
    else
    { // Se for par, a mediana é a média dos dois elementos centrais

        int mid1 = sortedArray[(size / 2) - 1];
        int mid2 = sortedArray[size / 2];
        median = (float)(mid1 + mid2) / 2.0; // cast para float
    }

    free(sortedArray); // Libera a memória alocada
    return median;
}

Node *removeMin(Node *tree)
{
    Node *min = getMin(tree);

    return removeNode(tree, min->data);
}

Node *changeKey(Node *root, int oldVal, int newVal)
{ // é basicamente remover o antigo valor e adicionar o novo
    // nao é uma mudança propriamente dito

    root = removeNode(root, oldVal);
    root = insertNode(root, newVal);

    return root;
}