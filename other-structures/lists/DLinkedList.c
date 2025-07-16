#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"

Dnode *dlist_create_dnode(int valor)
{
    Dnode *novo = (Dnode *)malloc(sizeof(Dnode));
    if (novo)
    {
        novo->dado = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo;
}

void dlist_insert_init(Dnode **cabeca, int valor)
{
    Dnode *novo = dlist_create_dnode(valor);
    if (!*cabeca)
    {
        *cabeca = novo;
        return;
    }
    novo->proximo = *cabeca;
    (*cabeca)->anterior = novo;
    *cabeca = novo;
}

void dlist_insert_end(Dnode **cabeca, int valor)
{
    Dnode *novo = dlist_create_dnode(valor);
    if (!*cabeca)
    {
        *cabeca = novo;
        return;
    }
    Dnode *atual = *cabeca;
    while (atual->proximo)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;
}

void dlist_remove_dnode(Dnode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    Dnode *atual = *cabeca;
    while (atual && atual->dado != chave)
    {
        atual = atual->proximo;
    }

    if (!atual)
        return; // Não encontrou

    if (atual->anterior)
    {
        atual->anterior->proximo = atual->proximo;
    }
    else
    { // É o primeiro nó
        *cabeca = atual->proximo;
    }

    if (atual->proximo)
    {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}

void dlist_get(Dnode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    Dnode *temp = *cabeca;
    while (temp && temp->dado != chave)
    {
        temp = temp->proximo;
    }

    if (!temp)
    {
        printf("Valor %d nao esta presente na lista dupla\n", chave);
    }
    else
    {
        printf("Valor %d esta presente na lista dupla\n", chave);
    }
}

void dlist_exibir(Dnode **cabeca)
{
    if (!*cabeca)
    {
        printf("Lista dupla vazia\n");
        return;
    }
    Dnode *atual = *cabeca;
    while (atual)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}
