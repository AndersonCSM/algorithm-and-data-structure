// implementar o algoritmo de ordenacao quicksort
#include <stdio.h>

// Fun��o para trocar dois elementos
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o de parti��o (esquema de Hoare)
// Retorna o �ndice 'j' final (limite da parti��o esquerda)
// O �ndice 'i' final (in�cio da parti��o direita) � retornado via ponteiro 'i_ptr'
int partition_hoare(int arr[], int first, int last, int* i_ptr, int pivot_mode) {
    int i = first;
    int j = last - 1; // 'last' � exclusivo, ent�o 'last-1' � o �ltimo �ndice real
    int pivot_val;

    // Se o subarray tem 0 ou 1 elemento, n�o h� o que particionar.
    // Esta verifica��o � mais para robustez, pois quickSort_hoare j� deve filtrar.
    if (first >= last -1) { // Equivale a last - first < 2
        *i_ptr = first; // ou i
        return last - 1; // ou j
    }

    int pivot_idx_choice;
    if (pivot_mode == 1) { // Piv� � o primeiro elemento
        pivot_idx_choice = first;
    } else if (pivot_mode == 2) { // Piv� � o �ltimo elemento
        pivot_idx_choice = j; // Usa j (que � last - 1)
    } else if (pivot_mode == 3) { // Piv� � o elemento do meio
        pivot_idx_choice = first + (j - first) / 2;
    } else {
        printf("Estrategia de pivo '%d' invalida. Usando 3 (meio).\n", pivot_mode);
        pivot_idx_choice = first + (j - first) / 2;
    }
    pivot_val = arr[pivot_idx_choice];

    // Particionamento
    while (i <= j) {
        // Move i para a direita enquanto arr[i] < pivot_val.
        // i pode ir at� 'last-1'. Se arr[last-1] < pivot_val, i se tornar� 'last'.
        while (i < last && arr[i] < pivot_val) {
            i++;
        }

        // Move j para a esquerda enquanto arr[j] > pivot_val.
        // j pode ir at� 'first'. Se arr[first] > pivot_val, j se tornar� 'first-1'.
        while (j >= first && arr[j] > pivot_val) {
            j--;
        }

        // Se i e j n�o se cruzaram (ou i ultrapassou j)
        if (i <= j) {
            troca(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    // Ap�s o loop, j < i.
    // j � o �ndice final da parti��o esquerda.
    // i � o �ndice inicial da parti��o direita.
    *i_ptr = i;
    return j;
}

// Fun��o principal do QuickSort (usando parti��o de Hoare)
void quickSort_hoare(int arr[], int first, int last, int pivot_mode) {
    // Condi��o de parada: se o subarray tem 1 ou 0 elementos (last - first < 2).
    if (first < last - 1) {
        int i_after_partition; // In�cio da parti��o direita
        int j_after_partition; // Fim da parti��o esquerda

        j_after_partition = partition_hoare(arr, first, last, &i_after_partition, pivot_mode);

        // Ordena a parti��o esquerda: [first ... j_after_partition]
        // O novo 'last' (exclusivo) � j_after_partition + 1
        quickSort_hoare(arr, first, j_after_partition + 1, pivot_mode);
       
        // Ordena a parti��o direita: [i_after_partition ... last-1]
        // O 'first' � i_after_partition, 'last' permanece o mesmo (exclusivo)
        quickSort_hoare(arr, i_after_partition, last, pivot_mode);
    }
}

// Fun��o para imprimir um array
void printArray(int arr[], int size) {
    for (int k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

// Fun��o principal para testar o algoritmo
int main() {
    int data_orig[] = {8, 7, 2, 1, 0, 9, 6, 3, 5, 4}; // Renomeado para evitar confus�o
    int n = sizeof(data_orig) / sizeof(data_orig[0]);
    int data_test[n]; // Array para cada teste

    printf("Array de entrada:\n");
    printArray(data_orig, n);

    for(int mode = 1; mode <= 3; mode++) {
        // Copia o array original para cada teste
        for(int k=0; k<n; ++k) {
            data_test[k] = data_orig[k];
        }

        printf("\nUsando estrategia de pivo %d ", mode);
        if (mode == 1) printf("(primeiro elemento):\n");
        else if (mode == 2) printf("(ultimo elemento):\n");
        else if (mode == 3) printf("(elemento do meio):\n");

        quickSort_hoare(data_test, 0, n, mode); // 'n' � o limite exclusivo 'last'
        printf("Array ordenado: ");
        printArray(data_test, n);
    }
    return 0;
}