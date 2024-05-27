/*------------------------------------------------------------------------/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          /
/                                                                         /
/                      Autor:  Felipe Santos Lins                         /
/                                                                         /
/                                                                         /
/             Objetivo: Inserção na Lista Ligada:                         /
/                                                                         /
/                Criamos uma nova estrutura de nó (Node).                 / 
/                Percorremos a lista até a posição de inserção.           /
/                Ajustamos os ponteiros para inserir o novo nó.           /
/                Medimos o tempo de execução com clock().                 /
/                                                                         /
/                                                                         /
/                                                         Data:27/05/2024 /
/------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserirNaLista(Node** head, int valor, int pos) {
    Node* novoNodo = (Node*)malloc(sizeof(Node));
    novoNodo->data = valor;

    if (pos == 0) {
        novoNodo->next = *head;
        *head = novoNodo;
        return;
    }

    Node* atual = *head;
    for (int i = 0; i < pos - 1 && atual != NULL; i++) {
        atual = atual->next;
    }

    if (atual == NULL) {
        return;
    }

    novoNodo->next = atual->next;
    atual->next = novoNodo;
}

void printLista(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    Node* segundo = NULL;
    Node* terceiro = NULL;
    Node* quarto = NULL;

    head = (Node*)malloc(sizeof(Node));
    segundo = (Node*)malloc(sizeof(Node));
    terceiro = (Node*)malloc(sizeof(Node));
    quarto = (Node*)malloc(sizeof(Node));

    head->data = 10;
    head->next = segundo;

    segundo->data = 25;
    segundo->next = terceiro;

    terceiro->data = 40;
    terceiro->next = quarto;

    quarto->data = 80;
    quarto->next = NULL;

    int valor = 30;
    int pos = 2;  // Insere após o segundo nó

    clock_t inicio = clock();

    inserirNaLista(&head, valor, pos);

    clock_t fim = clock();
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Lista após a inserção: ");
    printLista(head);
    printf("Tempo de execução: %f segundos\n", tempoGasto);

    // Liberar memória alocada
    Node* atual = head;
    Node* prox;
    while (atual != NULL) {
        prox = atual->next;
        free(atual);
        atual = prox;
    }

    return 0;
}
