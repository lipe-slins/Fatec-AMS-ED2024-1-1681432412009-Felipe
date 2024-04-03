#include <stdio.h>

int main() {

    int NumInt[5];
    int i, j, temp;

    printf("Digite 5 números inteiros positivos:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &NumInt[i]);
    }

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (NumInt[j] > NumInt[j + 1]) {
                temp = NumInt[j];
                NumInt[j] = NumInt[j + 1];
                NumInt[j + 1] = temp;
            }
        }
    }

    printf("Números em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", NumInt[i]);
    }
    printf("\n");

    return 0;
}