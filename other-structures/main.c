#include <stdio.h>
#include <stdlib.h>

#include "lists/CircularList.h"
#include "lists/DLinkedList.h"
#include "lists/LinkedList.h"
#include "queue/Queue.h"
#include "stack/Stack.h"

int main()
{

    int target = 0;

    switch (target)
    {
    case 0: // CircularList
    {
        Node *listaCircular = NULL;
        insert_init(&listaCircular, 30);
        insert_init(&listaCircular, 20);
        insert_end(&listaCircular, 40);

        printf("Lista Original: ");

        exibir_lista(&listaCircular);

        get(&listaCircular, 10);
        get(&listaCircular, 40);
    }
    case 1: // DLinkedList
    {
        Dnode *listaDuplamenteEncadeada = NULL;
        insert_init(&listaDuplamenteEncadeada, 30);
        insert_init(&listaDuplamenteEncadeada, 20);
        insert_end(&listaDuplamenteEncadeada, 40);

        printf("Lista Original: ");

        exibir_lista(&listaDuplamenteEncadeada);

        get(&listaDuplamenteEncadeada, 10);
        get(&listaDuplamenteEncadeada, 40);
    }
    case 2: // LinkedList
    {
        Node *lista = NULL;
        insert_init(&lista, 30);
        insert_init(&lista, 20);
        insert_end(&lista, 40);

        printf("Lista Original: ");

        exibir_lista(&lista);

        get(&lista, 10);
        get(&lista, 40);
    }
    case 3: // Queue
    {
        Queue queue;
        initQueue(&queue);

        append(&queue, 10);
        append(&queue, 20);
        append(&queue, 30);
        display(&queue);

        printf("elemento na frente: %d\n", front(&queue));
        printf("Desinfileirando: %d\n", dequeue(&queue));
        display(&queue);
    }
    case 4: // Stack
    {
        Stack stack;
        initStack(&stack);

        append(&stack, 10);
        append(&stack, 20);
        append(&stack, 30);
        display(&stack);
        pop(&stack);
        append(&stack, 40);
        display(&stack);

        printf("Elemento no topo: %d\n", top(&stack));
        printf("Desimpilhando: %d\n", pop(&stack));
        display(&stack);
    }
    default:
        printf("Opcao invalida!\n");
    }

    return 0;
}