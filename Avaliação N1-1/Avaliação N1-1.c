/------------------------------------------------------------------------/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados         /
/                       FelipeSantos Lins                                /
/                       Giovanni Monteiro                                /
/             Objetivo: Cadastro de Produtos                             /
/             Paradigama: programação modular (lista ligada)             /
/                                                                        /
/                                                         Data:02/04/2024/
/------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *prox;
} Produto;

void cadastrarProduto(Produto **lista, char nome[], int quantidade) {
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->prox = NULL;
 
    if (*lista == NULL) {
        *lista = novoProduto;
    } else {
        Produto *temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoProduto;
    }
    printf("Produto cadastrado com sucesso.\n");
}

Produto* buscarProduto(Produto *lista, char nome[]) {
    Produto *temp = lista;
    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;
}

void baixarEstoque(Produto *produto, int quantidade) {
    if (produto == NULL) {
        printf("Produto não encontrado.\n");
    } else if (produto->quantidade < quantidade) {
        printf("Quantidade insuficiente em estoque.\n");
    } else {
        produto->quantidade -= quantidade;
        printf("Baixa no estoque realizada com sucesso.\n");
    }
}
 
int main() {
    Produto *listaProdutos = NULL;
    int opcao, quantidade;
    char nomeProduto[50];
 
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Buscar Produto\n");
        printf("3. Baixar Estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                scanf("%s", nomeProduto);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &quantidade);
                cadastrarProduto(&listaProdutos, nomeProduto, quantidade);
                break;
            case 2:
                printf("Digite o nome do produto: ");
                scanf("%s", nomeProduto);
                Produto *produtoBuscado = buscarProduto(listaProdutos, nomeProduto);
                if (produtoBuscado != NULL) {
                    printf("Produto encontrado. Quantidade em estoque: %d\n", produtoBuscado->quantidade);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
                case 3:
                printf("Digite o nome do produto: ");
                scanf("%s", nomeProduto);
                printf("Digite a quantidade a ser baixada: ");
                scanf("%d", &quantidade);
                Produto *produtoParaBaixar = buscarProduto(listaProdutos, nomeProduto);
                baixarEstoque(produtoParaBaixar, quantidade);
                break;
                case 4:
                printf("Saindo do programa...\n");
                break;
                case 5:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);
 
    return 0;
}