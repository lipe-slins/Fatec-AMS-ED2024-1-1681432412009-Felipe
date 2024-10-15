#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função Bubble Sort com melhoria (uso de flag para otimização)
void bubbleSort(int arr[], int n) {
    int trocado;  // Flag para verificar se houve troca

    for (int i = 0; i < n - 1; i++) {
        trocado = 0;  // Reseta a flag em cada iteração

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem na ordem errada
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocado = 1;  // Marca que houve troca
            }
        }

        // Se nenhuma troca foi realizada, o array já está ordenado
        if (trocado == 0) {
            break;
        }
    }
}

int main() {
    int n;

    // Entrada do tamanho do array
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca dinamicamente o array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Entrada dos elementos do array
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);

    // Ordenação usando Bubble Sort
    bubbleSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado: ");
    printArray(arr, n);

    // Libera a memória alocada
    free(arr);

    return 0;
}
