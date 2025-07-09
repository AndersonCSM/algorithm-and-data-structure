#include <stdio.h>
#include <stdlib.h> // Para rand(), srand()
#include <time.h>   // Para time(), clock_t, clock(), CLOCKS_PER_SEC
#include <string.h> // Para memcpy()
#include <ctype.h>

#include "../include/auxiliar.h"
#include "../include/search-algorithms.h"
#include "../include/sorting-algorithms.h"

void gerar_array_aleatorio(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (n * 2);
}

void gerar_array_char_aleatorio(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (126 - 32 + 1)) + 32; // Caracteres ASCII
    }
}

void copiar_array_int(int *arr, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
}

void copiar_array_char(char *arr, char *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
}

int count_word(const char *text)
{
    char *texto_copia = strdup(text); // strdup aloca e copia a string
    if (texto_copia == NULL)
        return 0;

    char *delimitadores = " \t\n\r.,;:!?\"()";
    char *token = strtok(texto_copia, delimitadores);
    int count = 0;
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, delimitadores);
    }
    free(texto_copia);
    return count;
}

void extract_word(const char *text, char *word[], int n)
{
    char *texto_copia = strdup(text);
    if (texto_copia == NULL)
        return;

    char *delimitadores = " \t\n\r.,;:!?\"()";
    char *token = strtok(texto_copia, delimitadores);
    int i = 0;
    while (token != NULL && i < n)
    {
        word[i] = strdup(token); // Aloca memória para cada palavra
        i++;
        token = strtok(NULL, delimitadores);
    }
    free(texto_copia);
}

void free_word(char *text[], int n)
{
    for (int i = 0; i < n; i++)
    {
        free(text[i]);
    }
}

void sorting_switch(int opc, int *ordenado, int size)
{
    switch (opc)
    {
    case 0:
    {
        bubbleSort(ordenado, size);
        break;
    }
    case 1:
    {
        insertionSort(ordenado, size);
        break;
    }
    case 2:
    {
        mergeSort(ordenado, 0, size);
        break;
    }
    case 3:
    {
        quickSort(ordenado, 0, size);
        break;
    }
    }
}

void sorting_switch_c(int opc, int *ordenado, int size)
{
    switch (opc)
    {
    case 0:
    {
        bubbleSort_c(ordenado, size);
        break;
    }
    case 1:
    {
        insertionSort_c(ordenado, size);
        break;
    }
    case 2:
    {
        mergeSort_c(ordenado, 0, size);
        break;
    }
    case 3:
    {
        quickSort_c(ordenado, 0, size);
        break;
    }
    }
}