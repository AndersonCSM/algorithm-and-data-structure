#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const char *filename = "integer.bin";
    int n_arq;
    int num;
    FILE *arquivo;

    arquivo = fopen(filename, "rb");
    if (arquivo != NULL)
    {
        // fread retorna o n�mero de itens lidos com sucesso.
        if (fread(&n_arq, sizeof(int), 1, arquivo) == 1)
        {
            printf("Arquivo integer.bin encontrado!\n");
            printf("Ele cont�m o n�mero %d.\n\n", n_arq);
        }
        fclose(arquivo);
    }

    printf("Digite um inteiro: ");
    scanf("%d", &num);

    arquivo = fopen(filename, "wb"); // Abre para escrita bin�ria (cria o arquivo se n�o existir, ou trunca se existir)
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo integer.bin para escrita");
        return 1;
    }

    // fwrite retorna o n�mero de itens escritos com sucesso.
    if (fwrite(&num, sizeof(int), 1, arquivo) == 1)
    {
        printf("N�mero armazenado no arquivo integer.bin.\n");
    }

    fclose(arquivo);

    return 0;
}