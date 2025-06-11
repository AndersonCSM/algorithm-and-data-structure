// implementar o algoritmo de ordenaÃ§Ã£o quicksort

#include <stdio.h>

void quickSort(int *vetor, int inicio, int fim) {
    int i, j, pivo, aux;
    i = inicio; // i é o primeiro índice do vetor
    j = fim - 1; // j é o último índice do vetor
    pivo = vetor[(inicio + fim) / 2]; // pivô é o elemento do meio

    while (i <= j) { // Enquanto i e j não se cruzarem
        // busca o primeiro elemento menor que o pivô a partir de i
        while (vetor[i] < pivo && i < fim) {
            i++;
        }
        // busca o primeiro elemento maior que o pivô a partir de j
        while (vetor[j] > pivo && j > inicio) {
            j--;
        }
        if (i <= j) { // Enquanto i e j não se cruzarem
            // troca os elementos encontrados
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            // move os ponteiros i e j para continuar a busca
            i++;
            j--;
        }
    }
    // Chamada recursiva para ordenar as duas metades
    // j está a esquerda de i.
    if (j > inicio) {
        quickSort(vetor, inicio, j + 1);
    }
    if (i < fim) {
        quickSort(vetor, i, fim);
    }
}

int main() {
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    quickSort(vetor, 0, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Quick Sort ");
    return 0;
}