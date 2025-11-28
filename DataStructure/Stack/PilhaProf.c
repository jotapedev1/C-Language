#include <stdio.h>
#include <stdlib.h>

// Estrutura de cada nó da pilha
typedef struct Node {
    int num;              // Valor armazenado
    struct Node *prox;    // Ponteiro para o próximo nó
} Node;

// Estrutura principal da pilha
typedef struct {
    Node *top;            // Ponteiro para o topo da pilha
    int tam;              // Quantidade de elementos
} Pilha;

// ---------- FUNÇÕES AUXILIARES ----------

// Inicializa a pilha
void inicia(Pilha *p) {
    p->top = NULL;
    p->tam = 0;
}

// Retorna 1 se pilha vazia, 0 caso contrário
int vazia(Pilha *p) {
    return (p->top == NULL);
}

// Empilha um valor (push)
void push(Pilha *p, int valor) {
    Node *novo = (Node *) malloc(sizeof(Node));
    if (!novo) {
        printf("Sem memória disponível!\n");
        exit(1);
    }

    novo->num = valor;        // Armazena o valor
    novo->prox = p->top;      // Novo nó aponta para o antigo topo
    p->top = novo;            // Atualiza o topo
    p->tam++;

    printf("Elemento %d empilhado com sucesso!\n", valor);
}

// Desempilha um valor (pop)
int pop(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia, nada para remover.\n");
        return -1;
    }

    Node *remover = p->top;   // Nó que será removido
    int valor = remover->num; // Guarda o valor antes de liberar
    p->top = remover->prox;   // Move o topo para o próximo nó
    free(remover);            // Libera a memória
    p->tam--;

    printf("Elemento %d removido do topo.\n", valor);
    return valor;
}

// Exibe o conteúdo da pilha
void exibe(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    Node *aux = p->top;
    printf("\n--- PILHA (do topo para base) ---\n");
    int pos = p->tam;
    while (aux != NULL) {
        printf("[%d] -> %d\n", pos, aux->num);
        aux = aux->prox;
        pos--;
    }
    printf("-------------------------------\n\n");
}

// Libera todos os nós da pilha
void libera(Pilha *p) {
    Node *atual = p->top;
    Node *proxNode;

    while (atual != NULL) {
        proxNode = atual->prox;
        free(atual);
        atual = proxNode;
    }

    p->top = NULL;
    p->tam = 0;
}

// ---------- FUNÇÃO PRINCIPAL ----------
int main(void) {
    Pilha p;
    inicia(&p);  // Inicializa a pilha

    int opcao, valor;

    do {
        printf("\n=========== PILHA DINÂMICA EM C ===========\n");
        printf("1 - Empilhar (PUSH)\n");
        printf("2 - Desempilhar (POP)\n");
        printf("3 - Exibir pilha\n");
        printf("4 - Zerar pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            push(&p, valor);
        }
        else if (opcao == 2) {
            pop(&p);
        }
        else if (opcao == 3) {
            exibe(&p);
        }
        else if (opcao == 4) {
            libera(&p);
            printf("Pilha zerada!\n");
        }
        else if (opcao == 0) {
            printf("Encerrando programa...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    // Libera memória antes de sair
    libera(&p);
    return 0;
}
