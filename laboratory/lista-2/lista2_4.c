#include <stdio.h>
#include <locale.h>

void Mais(int *ptr)
{
    (*ptr)++;
}

int Incrementa(int num)
{
    return num + 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para portugu�s no Windows

    int num = 0;

    printf("Informe um n�mero:\n");
    scanf("%d", &num);

    printf("numero: %d\n", num);
    Mais(&num);

    printf("Resultado de Mais: %d\n", num);
    printf("Resultado de Incrementa: %d\n", Incrementa(num));
    printf("numero: %d\n", num);

    return 0;
}
