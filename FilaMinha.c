#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *pNextNode;
}Node;

typedef struct Queue{
    int orderNumber;
    char orderName[50];
    int queueSize;
    Node *pStart;
    Node *pEnd;
}Queue;

int isEmpty(){
    Queue *pQueue;
    return (pQueue->pStart == NULL);
}

void initializeQueue(){
    Queue *pQueue;
    pQueue->orderNumber = 0;
    //pQueue->orderName = '';
    pQueue->queueSize = 0;
    pQueue->pStart = NULL;
    pQueue->pEnd = NULL;
}

int generateOrderNumber(){
    Queue *pQueue;
    return pQueue->orderNumber++;
    
}

void enqueue(char orderName){
    Queue *pQueue;
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Alocação de memória falhou");
    }
    newNode->value = generateOrderNumber();
    pQueue->orderNumber = newNode->value;
    newNode->pNextNode = NULL;

    if(isEmpty(pQueue)){
        pQueue->pStart = newNode;
        pQueue->pEnd = newNode;
    }else{
        pQueue->pEnd->pNextNode = newNode;
        pQueue->pEnd = newNode;
    }

    pQueue->queueSize++;

    printf("Pedido de: %s cadastrado. Número gerado: %d", orderName, pQueue->orderNumber);
}

void dequeue(){
    Queue *pQueue;
    if(isEmpty(pQueue)){
        printf("Fila vazia, não há o que ser removido.");
    }
    Node *temp = pQueue->pStart;
    int value = temp->value;

    pQueue->pStart = temp->pNextNode;
    if(pQueue->pStart == NULL){
        pQueue->pEnd = NULL;
    }
    //TODO LIBERAR MEMORIA
    pQueue->queueSize--;

    printf("Primeira pessoa da fila foi atendida. Código atendido: %d", pQueue->orderNumber);
}

void showQueue(){
    Queue *pQueue;
    if(isEmpty(pQueue)){
        printf("Fila vazia, não há o que ser exibido.");
    }
    Node *temp = pQueue->pStart;
    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp = temp->pNextNode;
    }
    printf("-------------------------------\n\n");
}


// Libera toda a memória da fila
void freeQueue() {
    Queue *pQueue;
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
}

int main(){

    int escolha;
    char pedido[50];

    initializeQueue();

    do{
        printf("1 - Realizar um pedido \n 2 - Chamar pedido \n 3 - Exibir fila \n 4 - Exibir próximo pedido \n 5 - Exibir quantidade clientes na fila \n 6 - Expulsar clientes (zerar fila) \n 0 - Sair \n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Escreva o seu pedido: ");
            scanf("%s", pedido);
            enqueue((char)pedido);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            showQueue();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            freeQueue();
            break;
        case 0:
            printf("Saindo");
            break;
        default:
            break;
        }
    }while(escolha != 0);
}