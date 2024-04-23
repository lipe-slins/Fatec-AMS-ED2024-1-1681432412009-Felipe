#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_MAX_PILHA 100
#define TAMANHO_MAX_FORMULA 100

typedef struct {
    double pilha[TAMANHO_MAX_PILHA];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == TAMANHO_MAX_PILHA - 1;
}

void empilhar(Pilha *p, double valor) {
    if (cheia(p)) {
        printf("Estouro de Pilha\n");
        exit(EXIT_FAILURE);
    }
    p->pilha[++(p->topo)] = valor;
}

double desempilhar(Pilha *p) {
    if (vazia(p)) {
        printf("Subfluxo de Pilha\n");
        exit(EXIT_FAILURE);
    }
    return p->pilha[(p->topo)--];
}

void limpar(Pilha *p) {
    p->topo = -1;
}

double topo(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha esta vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->pilha[p->topo];
}

void imprimirPilha(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha esta vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%.2f ", p->pilha[i]);
    }
    printf("\n");
}

double avaliarRPN(char formula[]) {
    Pilha memoria;
    inicializar(&memoria);

    char *token = strtok(formula, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhar(&memoria, atof(token));
        } else {
            double y = desempilhar(&memoria);
            double x = desempilhar(&memoria);
            switch (token[0]) {
                case '+':
                    empilhar(&memoria, x + y);
                    break;
                case '-':
                    empilhar(&memoria, x - y);
                    break;
                case '*':
                    empilhar(&memoria, x * y);
                    break;
                case '/':
                    if (y == 0) {
                        printf("Erro: Divisao por zero\n");
                        exit(EXIT_FAILURE);
                    }
                    empilhar(&memoria, x / y);
                    break;
                default:
                    printf("Erro: Operador invalido\n");
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    if (memoria.topo != 0) {
        printf("Erro: RPN invalido\n");
        exit(EXIT_FAILURE);
    }

    return desempilhar(&memoria);
}

int main() {
    char formula[TAMANHO_MAX_FORMULA];
    printf("Digite a formula no formato RPN: ");
    fgets(formula, TAMANHO_MAX_FORMULA, stdin);
    formula[strcspn(formula, "\n")] = '\0'; // remove o caractere de nova linha

    double resultado = avaliarRPN(formula);
    printf("Resultado: %.2f\n", resultado);
    printf("Formula algebrica: %s\n", formula);

    return 0;
}
