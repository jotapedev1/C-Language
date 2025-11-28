#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *ptrNextNode;
}Node;

typedef struct Queue{
    Node *ptrFirstQueue;
    Node *ptrLastQueue;
    int size;
}Queue;

void startQueue(Queue *ptrQueue){
    ptrQueue->ptrFirstQueue = NULL;
    ptrQueue->ptrLastQueue = NULL;
    ptrQueue->size = 0;
}

int isEmpty(Queue *ptrQueue){
    return (ptrQueue->ptrFirstQueue == NULL);
}

void enqueue(Queue *ptrQueue, int newValue){
    Node *ptrNewNode = malloc(sizeof(Node));
    if(ptrNewNode == NULL){
        printf("Memory allocation failed \n");
    }

    ptrNewNode->value = newValue;
    ptrNewNode->ptrNextNode = NULL;
    ptrQueue->size++;

    if(isEmpty(ptrQueue)){
        ptrQueue->ptrFirstQueue=ptrNewNode;
        ptrQueue->ptrLastQueue=ptrNewNode;
    }else{
        ptrQueue->ptrLastQueue->ptrNextNode = ptrNewNode;
        ptrQueue->ptrLastQueue = ptrNewNode;
    }

    printf("Elemento %d enfileirado. \n", newValue);
}

int dequeue(Queue *ptrQueue){
    if(isEmpty(ptrQueue)){
        printf("Fila vazia \n");
        return -1;
    }

    Node *auxRemove = ptrQueue->ptrFirstQueue;
    int value = auxRemove->value;

    ptrQueue->ptrFirstQueue = auxRemove->ptrNextNode;
    if(ptrQueue->ptrFirstQueue == NULL){
        ptrQueue->ptrLastQueue = NULL;
    }

    free(auxRemove);
    ptrQueue->size--;
    printf("Primeiro elemento da fila foi atendido.\n");
    return value;
}

void showQueue(Queue *ptrQueue){
    if(isEmpty(ptrQueue)){
        printf("Fila vazia, nada há mostrar.\n");
        return;
    }
    Node *aux = ptrQueue->ptrFirstQueue;
    int position = 1;
    while(aux != NULL){
        printf(" %d | %d° |\n", aux->value, position);
        aux = aux->ptrNextNode;
        position++;        
    }
}

int main(){
    printf("\nHello World!\n");
    Queue q;

    enqueue(&q, 15);
    enqueue(&q, 30);
    enqueue(&q, 45);
    enqueue(&q, 60);
    showQueue(&q);

    printf("\n-------\n");

    dequeue(&q); //15
    dequeue(&q); //30

    showQueue(&q);
}

