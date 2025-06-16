#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    char pais[50];
    char continente[50];
} Local;

void preencher(int n, Local *vet)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nLocal %d:\n", i + 1);
        printf("Nome: ");
        fgets((vet + i)->nome, 50, stdin);
        (vet + i)->nome[strcspn((vet + i)->nome, "\n")] = 0;

        printf("Pa�s: ");
        fgets((vet + i)->pais, 50, stdin);
        (vet + i)->pais[strcspn((vet + i)->pais, "\n")] = 0;

        printf("Continente: ");
        fgets((vet + i)->continente, 50, stdin);
        (vet + i)->continente[strcspn((vet + i)->continente, "\n")] = 0;
    }
}

void exibir(int n, Local *vet)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nLocal %d:\n", i + 1);
        printf("  Nome: %s\n", (vet + i)->nome);
        printf("  Pa�s: %s\n", (vet + i)->pais); 
        printf("  Continente: %s\n", (vet + i)->continente);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Quantos locais voc� quer visitar nas pr�ximas f�rias?\n");
    scanf("%d", &n);
    getchar(); 

    Local *locais = (Local *)malloc(n * sizeof(Local));
    if (locais == NULL)
    {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    preencher(n, locais);
    printf("\nLocais que voc� escolheu:\n");
    exibir(n, locais);

    free(locais);
    return 0;
}