/-------------------------------------------------------------------------/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          /
/                                                                         /
/                      Autores:  Felipe Santos Lins                       /
/                                Giovanni  Monteiro                       /
/                                                                         /
/             Objetivo: Controlar Estoque de produtos                     /
/                                                                         /
/                                                                         /
/                                                         Data:06/04/2024 /
/------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int id;
    char nome[50];
    int quantidade;
    struct Produto *prox;
} Produto;

void cadastrarProduto(Produto **estoque) {
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    
    printf("ID: ");
    scanf("%d", &novoProduto->id);
    printf("Nome: ");
    scanf("%s", novoProduto->nome);
    printf("Quantidade: ");
    scanf("%d", &novoProduto->quantidade);
    novoProduto->prox = NULL;

    if (*estoque == NULL) {
        *estoque = novoProduto;
    } else {
        Produto *aux = *estoque;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoProduto;
    }
    printf("Produto cadastrado com sucesso.\n");
}

Produto *buscarProduto(Produto *estoque, int id) {
    Produto *aux = estoque;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void baixaProduto(Produto *estoque, int id, int quantidade) {
    Produto *produto = buscarProduto(estoque, id);
    if (produto != NULL) {
        if (produto->quantidade >= quantidade) {
            produto->quantidade -= quantidade;
            printf("Baixa de %d unidades do produto %s realizada com sucesso.\n", quantidade, produto->nome);
        } else {
            printf("Quantidade em estoque insuficiente para a baixa desejada.\n");
        }
    } else {
        printf("Produto com o ID especificado nao encontrado.\n");
    }
}

void imprimirEstoque(Produto *estoque) {
    printf("ID\tNome\tQuantidade\n");
    Produto *aux = estoque;
    while (aux != NULL) {
        printf("%d\t%s\t%d\n", aux->id, aux->nome, aux->quantidade);
        aux = aux->prox;
    }
}

int main() {
    Produto *estoque = NULL;
    int opcao, id, quantidade;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Buscar Produto\n");
        printf("3. Baixa de Produto\n");
        printf("4. Imprimir Estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(&estoque);
                break;
            case 2:
                printf("Digite o ID do produto a ser buscado: ");
                scanf("%d", &id);
                if (buscarProduto(estoque, id) != NULL) {
                    printf("Produto encontrado.\n");
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 3:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                printf("Digite a quantidade para baixa: ");
                scanf("%d", &quantidade);
                baixaProduto(estoque, id, quantidade);
                break;
            case 4:
                imprimirEstoque(estoque);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    Produto *temp;
    while (estoque != NULL) {
        temp = estoque;
        estoque = estoque->prox;
        free(temp);
    }

    return 0;
}
