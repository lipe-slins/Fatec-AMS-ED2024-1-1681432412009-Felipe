#include <stdio.h>

int main() {
    char nome[50];

    printf("Por favor, informe seu nome: ");
    scanf("%s", nome);

    printf("Olá Sr(a). %s\n", nome);

    return 0;
}
