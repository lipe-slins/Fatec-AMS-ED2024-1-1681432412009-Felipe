#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int idPaciente;
    int idSenha;
    char nomePaciente[50];
    int idadePaciente;
    char especialidade[50];
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node* proximo;
} Node;

typedef struct {
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

typedef struct {
    int idSenha;
    char textoSenha[50];
    char tipoAtendimento[20];
    int posicaoFila;
    int tamanhoFila; 
} Painel;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void adicionarPaciente(Fila* fila, Paciente paciente) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->paciente = paciente;
    novoNo->proximo = NULL;
    
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }
    
    fila->fim = novoNo;
    fila->tamanho++;
}

Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        Paciente pacienteVazio = {0, 0, "", 0, ""};
        return pacienteVazio;
    }

    Node* temp = fila->inicio;
    Paciente pacienteRemovido = temp->paciente;
    fila->inicio = temp->proximo;
    free(temp);
    fila->tamanho--;

    return pacienteRemovido;
}

void exibirPaciente(Paciente paciente) {
    printf("ID: %d\n", paciente.idPaciente);
    printf("Nome: %s\n", paciente.nomePaciente);
    printf("Idade: %d\n", paciente.idadePaciente);
    printf("Especialidade: %s\n", paciente.especialidade);
}

void adicionarChamadaPainel(Painel* painel, int idSenha, char* textoSenha, char* tipoAtendimento, int posicaoFila, int tamanhoFila) {
    painel->idSenha = idSenha;
    strcpy(painel->textoSenha, textoSenha);
    strcpy(painel->tipoAtendimento, tipoAtendimento);
    painel->posicaoFila = posicaoFila;
    painel->tamanhoFila = tamanhoFila; 
}

void exibirChamadaPainel(Painel painel) {
    printf("ID Senha: %d\n", painel.idSenha);
    printf("Texto Senha: %s\n", painel.textoSenha);
    printf("Tipo de Atendimento: %s\n", painel.tipoAtendimento);
    printf("Posição na Fila: %d\n", painel.posicaoFila);
}

int main() {
    Fila* filaNormal = criarFila();
    Fila* filaPrioritaria = criarFila();
    Fila* filaUrgente = criarFila();
    Painel painel;

    while (1) {
        int opcao;
        printf("Selecione uma opcao:\n");
        printf("1. Adicionar paciente a fila normal\n");
        printf("2. Adicionar paciente a fila prioritaria\n");
        printf("3. Adicionar paciente a fila urgente\n");
        printf("4. Atender proximo paciente\n");
        printf("5. Visualizar fila normal\n");
        printf("6. Visualizar fila prioritaria\n");
        printf("7. Visualizar fila urgente\n");
        printf("8. Visualizar chamada no painel\n");
        printf("9. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 9) {
            break;
        }

        switch (opcao) {
            case 1:
                {
                    Paciente novoPaciente;
                    printf("ID do paciente: ");
                    scanf("%d", &novoPaciente.idPaciente);
                    printf("ID da senha: ");
                    scanf("%d", &novoPaciente.idSenha);
                    printf("Nome do paciente: ");
                    scanf("%s", novoPaciente.nomePaciente);
                    printf("Idade do paciente: ");
                    scanf("%d", &novoPaciente.idadePaciente);
                    printf("Especialidade: ");
                    scanf("%s", novoPaciente.especialidade);
                    adicionarPaciente(filaNormal, novoPaciente);
                    

                }
                break;
            case 2:
                {
                    Paciente novoPaciente;
                    printf("ID do paciente: ");
                    scanf("%d", &novoPaciente.idPaciente);
                    printf("ID da senha: ");
                    scanf("%d", &novoPaciente.idSenha);
                    printf("Nome do paciente: ");
                    scanf("%s", novoPaciente.nomePaciente);
                    printf("Idade do paciente: ");
                    scanf("%d", &novoPaciente.idadePaciente);
                    printf("Especialidade: ");
                    scanf("%s", novoPaciente.especialidade);
                    adicionarPaciente(filaPrioritaria, novoPaciente);

                }
                break;
            case 3:
                {
                    Paciente novoPaciente;
                    printf("ID do paciente: ");
                    scanf("%d", &novoPaciente.idPaciente);
                    printf("ID da senha: ");
                    scanf("%d", &novoPaciente.idSenha);
                    printf("Nome do paciente: ");
                    scanf("%s", novoPaciente.nomePaciente);
                    printf("Idade do paciente: ");
                    scanf("%d", &novoPaciente.idadePaciente);
                    printf("Especialidade: ");
                    scanf("%s", novoPaciente.especialidade);
                    adicionarPaciente(filaUrgente, novoPaciente);

                }
                break;
            case 4:
                {
                    if (!filaVazia(filaUrgente)) {
                        printf("Atendendo paciente urgente:\n");
                        exibirPaciente(removerPaciente(filaUrgente));
                    } else if (!filaVazia(filaPrioritaria)) {
                        printf("Atendendo paciente prioritario:\n");
                        exibirPaciente(removerPaciente(filaPrioritaria));
                    } else if (!filaVazia(filaNormal)) {
                        printf("Atendendo paciente normal:\n");
                        exibirPaciente(removerPaciente(filaNormal));
                    } else {
                        printf("Nao ha pacientes para atender.\n");
                    }
                }
                break;
            case 5:
                printf("Fila normal:\n");
                break;
            case 6:
                printf("Fila prioritaria:\n");
                break;
            case 7:
                printf("Fila urgente:\n");
                break;
            case 8:
                printf("Chamada no painel:\n");
                exibirChamadaPainel(painel);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}