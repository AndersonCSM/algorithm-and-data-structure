#include <stdio.h>

// Função para trocar dois elementos
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição (esquema de Lomuto)
int partition(int arr[], int low, int high, int pivot_mode) {
    int pivot_idx;

    if (pivot_mode == 1) { // Pivô é o primeiro elemento
        pivot_idx = low;
    } else if (pivot_mode == 2) { // Pivô é o último elemento
        pivot_idx = high;
    } else if (pivot_mode == 3) { // Pivô é o elemento do meio
        pivot_idx = low + (high - low) / 2; // Evita overflow para low+high grande
    } else {
        // Estratégia inválida, usa 3 (meio) como padrão
        printf("Estrategia de pivo '%d' invalida. Usando 3 (meio).\n", pivot_mode);
        pivot_idx = low + (high - low) / 2;
    }

    // Move o pivô escolhido para o final do subarray (posição high) | estratégia de Lomuto
    troca(&arr[pivot_idx], &arr[high]);
    int pivot_value = arr[high]; // O valor do pivô agora está em arr[high]
    int i = (low - 1); // Índice do menor elemento [Começa em -1 para que o primeiro elemento seja colocado corretamente]

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot_value) {
            i++; // Incrementa o índice do menor elemento
            troca(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô (que está em arr[high]) em sua posição final correta
    troca(&arr[i + 1], &arr[high]);
    return (i + 1); // Retorna o índice da posição final do pivô
}

// Função principal do QuickSort
void quickSort(int arr[], int low, int high, int pivot_mode) {
    if (low < high) {
        // pi é o índice de partição, arr[pi] está agora no lugar certo
        int pi = partition(arr, low, high, pivot_mode);

        // Ordenar separadamente os elementos antes e depois da partição
        quickSort(arr, low, pi - 1, pivot_mode);
        quickSort(arr, pi + 1, high, pivot_mode);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal para testar o algoritmo
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Array de entrada:\n");
    printArray(data, n);

    // Crie cópias do array para testar cada estratégia independentemente
    int data_copy1[n], data_copy2[n], data_copy3[n];
    for(int i=0; i<n; ++i) {
        data_copy1[i] = data[i];
        data_copy2[i] = data[i];
        data_copy3[i] = data[i];
    }


    printf("\nUsando estrategia de pivo 1 (primeiro elemento):\n");
    quickSort(data_copy1, 0, n - 1, 1);
    printf("Array ordenado: ");
    printArray(data_copy1, n);

    printf("\nUsando estrategia de pivo 2 (ultimo elemento):\n");
    quickSort(data_copy2, 0, n - 1, 2);
    printf("Array ordenado: ");
    printArray(data_copy2, n);
    
    printf("\nUsando estrategia de pivo 3 (elemento do meio):\n");
    quickSort(data_copy3, 0, n - 1, 3);
    printf("Array ordenado: ");
    printArray(data_copy3, n);

    // Teste com estratégia padrão (caso o usuário não especifique ou use uma inválida)
    // int data_default[] = {8, 7, 2, 1, 0, 9, 6};
    // printf("\nUsando estrategia de pivo padrao (meio, implicito por quickSort sem o ultimo arg ou com valor invalido):\n");
    // quickSort(data_default, 0, n - 1, 3); // ou quickSort(data_default, 0, n - 1, 99) para testar o default
    // printf("Array ordenado: ");
    // printArray(data_default, n);


    return 0;
}