#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------- ESTRUTURAS --------------------

typedef struct Node {
    char nome[50];
    int idade;
    char atendimento[100];
    struct Node* prox;
} Node;

typedef struct {
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

// -------------------- FUNÇÕES BÁSICAS --------------------

void inicializaFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int filaVazia(Fila* f) {
    return (f->inicio == NULL);               // L1
}

void enqueue(Fila* f, char nome[], int idade, char atendimento[]) {

    Node* novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória!");
        return;
    }

    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->atendimento, atendimento);
    novo->prox = NULL;

    if (filaVazia(f)) {                      // L2
        f->inicio = novo;                    // L3
    } else {
        f->fim->prox = novo;                 // L4
    }

    f->fim = novo;                           // L5
    f->tamanho++;
}

void dequeue(Fila* f) {

    if (filaVazia(f)) {                      // L6
        printf("\nFila vazia.\n");
        return;
    }

    Node* aux = f->inicio;

    printf("\n🩺 Atendendo: %s | %d anos | %s\n",
           aux->nome, aux->idade, aux->atendimento);

    f->inicio = aux->prox;                   // L7

    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);
    f->tamanho--;
}

// -------------------- REGRAS DE PRIORIDADE --------------------

int contadorPrioritario = 0;

void atenderPaciente(Fila* fp, Fila* fn) {

    // A cada 2 prioritários → atender 1 normal
    if (contadorPrioritario >= 2 && !filaVazia(fn)) {
        printf("\n➡️ Critério: 2 prioritários → chamar NORMAL\n");
        dequeue(fn);                          // L8
        contadorPrioritario = 0;
        return;
    }

    // Se há prioritário → atender prioritário
    if (!filaVazia(fp)) {                     // L9
        printf("\n➡️ Atendendo PRIORITÁRIO\n");
        dequeue(fp);                          // L10
        contadorPrioritario++;
        return;
    }

    // Se não há prioritário → atender normal
    if (!filaVazia(fn)) {
        printf("\n➡️ Fila prioritária vazia → chamar NORMAL\n");
        dequeue(fn);                          // L11
        contadorPrioritario = 0;
        return;
    }

    printf("\nNenhum paciente na fila.\n");
}

// -------------------- MENU PRINCIPAL --------------------

int main() {

    Fila filaPrioritaria, filaNormal;
    inicializaFila(&filaPrioritaria);
    inicializaFila(&filaNormal);

    // Inserção inicial automática (3 prioritários e 3 normais)
    enqueue(&filaPrioritaria, "PacienteP1", 70, "Consulta");   // L12
    enqueue(&filaPrioritaria, "PacienteP2", 80, "Retorno");    // L13
    enqueue(&filaPrioritaria, "PacienteP3", 65, "Exame");      // L14

    enqueue(&filaNormal, "PacienteN1", 25, "Vacina");          // L15
    enqueue(&filaNormal, "PacienteN2", 40, "Curativo");        // L16
    enqueue(&filaNormal, "PacienteN3", 33, "Consulta");        // extra não numerado

    int opcao;
    char nome[50], atendimento[100];
    int idade, prioridade;

    do {
        printf("\n========= UBS - SISTEMA DE FILA =========\n");
        printf("1 - Adicionar paciente\n");
        printf("2 - Chamar próximo\n");
        printf("3 - Exibir filas\n");
        printf("0 - Sair\n");
        printf("=========================================\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {

            case 1:
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Idade: ");
                scanf("%d", &idade);
                getchar();

                printf("Atendimento: ");
                fgets(atendimento, 100, stdin);
                atendimento[strcspn(atendimento, "\n")] = '\0';

                printf("Prioridade? (0 normal | 1 prioritário): ");
                scanf("%d", &prioridade);
                getchar();

                if (prioridade == 1)
                    enqueue(&filaPrioritaria, nome, idade, atendimento);
                else
                    enqueue(&filaNormal, nome, idade, atendimento);
                break;

            case 2:
                atenderPaciente(&filaPrioritaria, &filaNormal);
                break;

            case 3:
                printf("\n--- Fila Prioritária ---\n");
                Node* aux = filaPrioritaria.inicio;
                while (aux) {
                    printf("%s | %d anos | %s\n", aux->nome, aux->idade, aux->atendimento);
                    aux = aux->prox;
                }

                printf("\n--- Fila Normal ---\n");
                aux = filaNormal.inicio;
                while (aux) {
                    printf("%s | %d anos | %s\n", aux->nome, aux->idade, aux->atendimento);
                    aux = aux->prox;
                }
                break;

            case 0:
                printf("\nEncerrando...\n");
        }

    } while (opcao != 0);

    return 0;
}
