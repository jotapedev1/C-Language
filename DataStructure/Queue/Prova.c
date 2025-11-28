#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nome[50];
    char atendimento[50];
    int idade;
    struct Node *ptrNextNode;
}Node;

typedef struct Queue{
    Node *firstQueue;
    Node *lastQueue;
    int size;
}Queue;

void startQueue(Queue *ptrQueue){
    ptrQueue->firstQueue = NULL;
    ptrQueue->lastQueue = NULL;
    ptrQueue->size = 0;
}

int isEmpty(Queue *ptrQueue){
    return(ptrQueue->firstQueue == NULL);
}

enqueue(Queue *ptrQueue, char nome[], char atendimento[], int idade){
    
    Node *ptrNode = malloc(sizeof(Node));
    
    if(ptrNode == NULL){
        printf("Memory allocation error");
        exit(1);
    }
    
    strcpy(ptrNode->nome, nome);
    strcpy(ptrNode->atendimento, atendimento);
    ptrNode->idade = idade;

    ptrNode->ptrNextNode = NULL;

    if(isEmpty(ptrQueue)){
        ptrQueue->firstQueue = ptrNode;
    }else{
        ptrQueue->lastQueue->ptrNextNode = ptrNode;
    }

    ptrQueue->lastQueue = ptrNode;
    ptrQueue->size++;
}

void dequeue(Queue *ptrQueue){
    if(isEmpty(ptrQueue)){
        printf("Fila vazia, ninguém para chamar\n");
        return;
    }
    Node *aux = ptrQueue->firstQueue;
    if(ptrQueue->firstQueue == NULL){
        ptrQueue->lastQueue = NULL;
    }
    
    ptrQueue->firstQueue = ptrQueue->firstQueue->ptrNextNode;

    free(aux);
    ptrQueue->size--;
}

int priorityCount = 0;
void callPatient(Queue *fn, Queue *fp){
    if(priorityCount >= 2 && !isEmpty(fn)){
        printf("Atendimento normal\n");
        dequeue(fn);
        priorityCount = 0;
        return;
    }
    if(priorityCount < 2 && !isEmpty(fp)){
        printf("Atendimento prioritário\n");
        dequeue(fp);
        priorityCount++;
        return;
    }
    if(!isEmpty(fn)){
        printf("Atendimento\n");
        dequeue(fn);
        priorityCount = 0;
        return;
    }
    printf("Nenhum paciente nas filas.\n");
}


int main(){
    Queue normal, prioritario;

    startQueue(&normal);
    startQueue(&prioritario);

    // INSERINDO PESSOAS NA FILA
    enqueue(&normal, "João", "Consulta Geral", 22);
    enqueue(&prioritario, "Maria", "Gestante", 30);
    enqueue(&prioritario, "Carlos", "Idoso", 75);
    enqueue(&normal, "Ana", "Dor de cabeça", 19);
    enqueue(&prioritario, "Rosa", "Idosa", 82);

    // CHAMANDO PACIENTES
    printf("\n--- Chamadas ---\n");
    callPatient(&normal, &prioritario); // prioridade
    callPatient(&normal, &prioritario); // prioridade
    callPatient(&normal, &prioritario); // normal
    callPatient(&normal, &prioritario); // prioridade
    callPatient(&normal, &prioritario); // prioridade
    callPatient(&normal, &prioritario); // normal

    return 0;
}