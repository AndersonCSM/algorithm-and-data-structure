#include <stdio.h>
#include <stdlib.h>

#include "CircularList.h"

CNode *clist_create_node(int valor)
{
    CNode *novo = malloc(sizeof(CNode));
    if (novo)
    {
        novo->dado = valor;
        novo->proximo = NULL;
    }
    return novo;
}

void clist_insert_init(CNode **cabeca, int valor)
{
    CNode *novo = clist_create_node(valor);
    if (!novo)
        return;

    if (!*cabeca)
    {
        novo->proximo = novo;
        *cabeca = novo;
    }
    else
    {
        CNode *atual = *cabeca;
        while (atual->proximo != *cabeca)
        {
            atual = atual->proximo;
        }
        novo->proximo = *cabeca;
        atual->proximo = novo;
        *cabeca = novo;
    }
}

void clist_insert_end(CNode **cabeca, int valor)
{
    CNode *novo = clist_create_node(valor);
    if (!novo)
        return;

    if (!*cabeca)
    {
        novo->proximo = novo;
        *cabeca = novo;
    }
    else
    {
        CNode *atual = *cabeca;
        while (atual->proximo != *cabeca)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->proximo = *cabeca;
    }
}

void clist_pop_node(CNode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    CNode *temp = *cabeca;
    CNode *anterior = NULL;

    do
    {
        if (temp->dado == chave)
            break;
        anterior = temp;
        temp = temp->proximo;
    } while (temp != *cabeca);

    if (temp->dado != chave)
        return;

    if (temp->proximo == temp)
    {
        free(temp);
        *cabeca = NULL;
        return;
    }

    if (temp == *cabeca)
    {
        CNode *ultimo = *cabeca;
        while (ultimo->proximo != *cabeca)
        {
            ultimo = ultimo->proximo;
        }
        *cabeca = temp->proximo;
        ultimo->proximo = *cabeca;
        free(temp);
    }
    else
    {
        anterior->proximo = temp->proximo;
        free(temp);
    }
}

void clist_get(CNode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    CNode *atual = *cabeca;
    do
    {
        if (atual->dado == chave)
        {
            printf("Valor %d esta presente na lista circular\n", chave);
            return;
        }
        atual = atual->proximo;
    } while (atual != *cabeca);
    printf("Valor %d nao esta presente na lista circular\n", chave);
}

void clist_exibir(CNode **cabeca)
{
    if (!*cabeca)
    {
        printf("Lista circular vazia\n");
        return;
    }
    CNode *atual = *cabeca;
    do
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != *cabeca);
    printf("\n");
}
