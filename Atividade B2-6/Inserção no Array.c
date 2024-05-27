/*------------------------------------------------------------------------/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          /
/                                                                         /
/                      Autor:  Felipe Santos Lins                         /
/                                                                         /
/                                                                         /
/             Objetivo: Inserção no Array:                                /
/                                                                         /
/            Calculamos a posição de inserção (pos).                      /
/            Deslocamos os elementos à direita dessa posição.             /
/            Inserimos o valor na posição especificada.                   /
/            Medimos o tempo de execução com clock().                     /
/                                                                         /
/                                                                         /
/                                                         Data:27/05/2024 /
/------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

void inserirNoArray(int arr[], int *size, int valor, int pos) {
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = valor;
    (*size)++;
}

int main() {
    int arr[6] = {10, 25, 40, 80};  // Inicialmente 4 elementos
    int size = 4;
    int valor = 30;
    int pos = size / 2;

    clock_t inicio = clock();

    inserirNoArray(arr, &size, valor, pos);

    clock_t fim = clock();
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Array após a inserção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTempo de execução: %f segundos\n", tempoGasto);

    return 0;
}
