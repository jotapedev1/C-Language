/*
FATEC Osasco - Desenvolvimento de Software Multiplataforma (2º semestre) - Estrutura de Dados

Dupla:
João Pedro da Penha Santos
Cauã Ceccaroni dos Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *pNextNode;
} Node;

typedef struct Queue {
    int orderNumber;
    char orderName[50];
    int queueSize;
    Node *pStart;
    Node *pEnd;
} Queue;

int isEmpty(Queue *pQueue) {
    return (pQueue->pStart == NULL);
}

void initializeQueue(Queue *pQueue) {
    pQueue->orderNumber = 0;
    pQueue->queueSize = 0;
    pQueue->pStart = NULL;
    pQueue->pEnd = NULL;
}

int generateOrderNumber(Queue *pQueue) {
    return pQueue->orderNumber++;
}

void enqueue(Queue *pQueue, char orderName[]) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alocação de memória falhou\n");
        return;
    }

    newNode->value = generateOrderNumber(pQueue);
    newNode->pNextNode = NULL;

    if (isEmpty(pQueue)) {
        pQueue->pStart = newNode;
        pQueue->pEnd = newNode;
    } else {
        pQueue->pEnd->pNextNode = newNode;
        pQueue->pEnd = newNode;
    }

    pQueue->queueSize++;

    printf("Pedido de '%s' cadastrado. Número gerado: %d\n", orderName, newNode->value);
}

void dequeue(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        printf("Fila vazia, não há o que ser removido.\n");
        return;
    }

    Node *temp = pQueue->pStart;
    int value = temp->value;

    pQueue->pStart = temp->pNextNode;
    if (pQueue->pStart == NULL) {
        pQueue->pEnd = NULL;
    }

    free(temp);
    pQueue->queueSize--;

    printf("Primeira pessoa da fila foi atendida. Código atendido: %d\n", value);
}

void showQueue(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        printf("Fila vazia, não há o que ser exibido.\n");
        return;
    }

    Node *temp = pQueue->pStart;
    printf("Fila atual: ");
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->pNextNode;
    }
    printf("NULL\n");
    printf("-------------------------------\n\n");
}

// Exibir o próximo pedido da fila
void showNextOrder(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        printf("Fila vazia.\n");
    } else {
        printf("Próximo pedido: %d\n", pQueue->pStart->value);
    }
}

// Exibir quantidade de clientes na fila
void showQueueSize(Queue *pQueue) {
    printf("Há %d cliente(s) na fila.\n", pQueue->queueSize);
}

// Libera toda a memória da fila
void freeQueue(Queue *pQueue) {
    Node *temp = pQueue->pStart;
    Node *pNextNode;
    while (temp != NULL) {
        pNextNode = temp->pNextNode;
        free(temp);
        temp = pNextNode;
    }
    pQueue->pStart = NULL;
    pQueue->pEnd = NULL;
    pQueue->queueSize = 0;
    pQueue->orderNumber = 0;
    printf("Fila zerada com sucesso.\n");
}

int main() {
    Queue queue;
    int escolha;
    char pedido[50];

    initializeQueue(&queue);

    do {
        printf("\n------ MENU ------\n");
        printf("1 - Realizar um pedido\n");
        printf("2 - Chamar pedido\n");
        printf("3 - Exibir fila\n");
        printf("4 - Exibir próximo pedido\n");
        printf("5 - Exibir quantidade de clientes na fila\n");
        printf("6 - Expulsar clientes (zerar fila)\n");
        printf("0 - Sair\n");
        printf("------------------\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Escreva o seu pedido: ");
                scanf("%s", pedido);
                enqueue(&queue, pedido);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                showQueue(&queue);
                break;
            case 4:
                showNextOrder(&queue);
                break;
            case 5:
                showQueueSize(&queue);
                break;
            case 6:
                freeQueue(&queue);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
