#include <stdio.h>


void aplicarDesconto(float *preco, float desconto) {
    *preco = *preco - (*preco * (desconto / 100));
}

int main() {
    float preco, preco_original, desconto;

    printf("Insira o preço do produto: ");
    scanf("%f", &preco);
    
    preco_original = preco;

    printf("Insira o desconto a ser aplicado (em %%): ");
    scanf("%f", &desconto);

    aplicarDesconto(&preco, desconto);

    printf("Preço original: R$ %.2f\n", preco_original);
    printf("Desconto aplicado: %.f%%\n", desconto);
    printf("Preço final após desconto: R$ %.2f\n", preco);
}