#include <stdio.h>
#include <stdlib.h>

/*
=========================================================
ATIVIDADE PRÁTICA — FILA EM C
---------------------------------------------------------
OBJETIVO:
Compreender e manipular a estrutura de dados dinâmica 
do tipo FILA (First In, First Out).
=========================================================
*/

// Estrutura de cada nó da fila
typedef struct Node {
    int num;              // valor armazenado
    struct Node *prox;    // ponteiro para o próximo nó
} Node;

// Estrutura principal da fila
typedef struct Fila{
    Node *ini;            // ponteiro para o início da fila
    Node *fim;            // ponteiro para o final da fila
    int tam;              // contador de elementos
} Fila;

// ---------- FUNÇÕES BASE ----------

// Inicializa a fila
void inicia(Fila *f) {
    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;
}

// Verifica se a fila está vazia
int vazia(Fila *f) {
    return (f->ini == NULL);
}

// Enfileira um valor (enqueue)
void enqueue(Fila *f, int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    novo->num = valor;
    novo->prox = NULL;

    if (vazia(f)) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tam++;
    printf("Elemento %d enfileirado com sucesso!\n", valor);
}

// Desenfileira um valor (dequeue)
int dequeue(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia, nada a remover.\n");
        return -1;
    }

    Node *remover = f->ini;
    int valor = remover->num;

    f->ini = remover->prox;
    if (f->ini == NULL) f->fim = NULL; // fila ficou vazia

    free(remover);
    f->tam--;

    printf("Elemento %d removido da fila.\n", valor);
    return valor;
}

// Exibe o conteúdo da fila
void exibe(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    Node *aux = f->ini;
    printf("\n--- FILA (do início -> fim) ---\n");
    int pos = 1;
    while (aux != NULL) {
        printf("[%d] -> %d\n", pos, aux->num);
        aux = aux->prox;
        pos++;
    }
    printf("-------------------------------\n\n");
}

// Libera toda a memória da fila
void libera(Fila *f) {
    Node *atual = f->ini;
    Node *proxNode;
    while (atual != NULL) {
        proxNode = atual->prox;
        free(atual);
        atual = proxNode;
    }
    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;
}

// ---------- PROGRAMA PRINCIPAL ----------
int main(void) {
    Fila f;
    inicia(&f);

    int opcao, valor;

    do {
        printf("\n=========== MENU FILA ===========\n");
        printf("1 - Enfileirar (ENQUEUE)\n");
        printf("2 - Desenfileirar (DEQUEUE)\n");
        printf("3 - Exibir fila\n");
        printf("4 - Zerar fila\n");
        printf("0 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            printf("Digite o valor a enfileirar: ");
            scanf("%d", &valor);
            enqueue(&f, valor);
        }
        else if (opcao == 2) {
            dequeue(&f);
        }
        else if (opcao == 3) {
            exibe(&f);
        }
        else if (opcao == 4) {
            libera(&f);
            printf("Fila zerada!\n");
        }

    } while (opcao != 0);

    libera(&f);
    return 0;
}

