#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const char *filename = "vet.dat";
    FILE *arq;
    int numeros[100];
    int cont = 0;
    int num;

    arq = fopen(filename, "rb");
    if (arq != NULL)
    {
        int qtd;
        if (fread(&qtd, sizeof(int), 1, arq) == 1) // j� avan�a o ponteiro do arq bin�rio
        {
            if (qtd > 0)
            {
                printf("O arq vet.dat cont�m:\n");

                int numero_lido;
                for (int i = 0; i < qtd; i++)
                {
                    if (fread(&numero_lido, sizeof(int), 1, arq) == 1) // ponteiro j� leu o inteiro respons�vel pela quantidade de elementos
                    {
                        printf("%d ", numero_lido);
                    }
                    else
                    {
                        fprintf(stderr, "Erro ao ler dado do arq %s existente.\n", filename);
                        break;
                    }
                }
                printf("\n");
            }
        }
        fclose(arq);
    }

    // Se arq == NULL
    printf("Digite n�meros (zero para encerrar):\n");
    while (cont < 100)
    {
        if (scanf("%d", &num) != 1) // concatenado para tratamento de entrada -> mais otimizado que as vers�es anteriores
        {
            printf("Entrada inv�lida. Por favor, digite um n�mero inteiro.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (num == 0)
        {
            break;
        }

        numeros[cont] = num;
        cont++;
    }

    arq = fopen(filename, "wb");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arq vet.dat para escrita");
        return 1;
    }

    // Escreve a quantidade de n�meros (pode ser 0 se nenhum n�mero v�lido foi digitado)
    if (fwrite(&cont, sizeof(int), 1, arq) != 1) // j� avan�a o ponteiro do arq bin�rio
    {
        fprintf(stderr, "Erro ao escrever a quantidade no arq %s.\n", filename);
        fclose(arq);
        return 1;
    }

    for (int i = 0; i < cont; i++)
    {
        if (fwrite(&numeros[i], sizeof(int), 1, arq) != 1)
        {
            fprintf(stderr, "Erro ao escrever o n�mero %d no arq %s.\n", i + 1, filename);
            fclose(arq);
            return 1;
        }
    }

    printf("%d n�meros foram armazenados em vet.dat.\n", cont);
    fclose(arq);

    return 0;
}
