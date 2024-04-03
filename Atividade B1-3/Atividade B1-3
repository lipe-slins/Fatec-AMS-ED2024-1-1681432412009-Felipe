#include <stdio.h>

#define TAMANHO_ARRAY 5

float encontrarMaiorElemento(float array[]) {
    float maior = array[0]; 
    for (int i = 1; i < TAMANHO_ARRAY; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

float calcularSoma(float array[]) {
    float soma = 0; 
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        soma += array[i];
    }
    return soma;
}

void imprimirArray(float array[]) {
    printf("Array:");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.2f ", array[i]); 
    }
    printf("\n");
}

void modificarArray(float array[], float valor) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        array[i] *= valor; 
    }
}

int main() {
    float notas[TAMANHO_ARRAY];

    printf("Digite as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d:", i + 1);
        scanf("%f", &notas[i]); 
    }

    printf("Maior elemento: %.2f\n", encontrarMaiorElemento(notas));
    printf("Soma dos elementos: %.2f\n", calcularSoma(notas));

    imprimirArray(notas);

    float valor;
        printf("Digite o valor pelo qual multiplicar os elementos do array:");
        scanf("%f", &valor);
        modificarArray(notas, valor);
        printf("Array modificado:\n");
        imprimirArray(notas);

    return 0;
}
