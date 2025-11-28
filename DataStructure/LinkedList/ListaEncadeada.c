#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *pNextNode;
} Node;

//função para criação de nó e não ter de repetir codigo 
Node* creatingNode(int newValue){
    Node *newNode = (Node*) malloc(sizeof(Node));//aloca memoria do tamanho da estrutura Node
    if (newNode == NULL) {
        perror("malloc failed");//caso falhe
        exit(EXIT_FAILURE);
    }
    newNode->value = newValue;
    newNode->pNextNode = NULL;//setta o proximo nó como nulo
    return newNode;
}

void addFirst(struct Node **startRef, int newValue){//ponteiro apontando para o ponteiro de Node
    Node *newNode = creatingNode(newValue);//alocando memória e settando next como NULL
    newNode->pNextNode = *startRef;
    *startRef = newNode;
}

int getFirst(struct Node *startRef){
    if(startRef != NULL){ //se a lista não estiver vazia...
        Node *currentNode = startRef; //criando ponteiro que aponta para o primeiro nó da lista
        return currentNode->value; //retorna valor do nó atual, que é o primeiro
    }else{
        return -1; //lista vazia
    }
}

void addLast(struct Node **startRef, int newValue){ //ponteiro apontando para o ponteiro de Node
    Node *newNode = creatingNode(newValue); //criando novo nó, alocando memoria, settando próximo como nulo
    if(*startRef == NULL){ //se lista estiver vazia..
        *startRef = newNode; //primeiro nó passa a ser o novo nó
        return;
    }
    Node *currentNode = *startRef; //criando ponteiro que aponta para primeiro nó da lista
    while (currentNode->pNextNode != NULL)//enquanto meu próximo nó não for nulo...
    {
        currentNode = currentNode->pNextNode;//percorre nó por nó
    }
    currentNode->pNextNode = newNode;//saindo do loop, pq encontramos o último nó, criando um novo no final
}

int getLast(struct Node *startRef){
    if(startRef != NULL){
        Node *currentNode = startRef; //criando ponteiro que aponta para primeiro nó da lista
        while (currentNode->pNextNode != NULL)//enquanto meu próximo nó não for nulo...
        {
            currentNode = currentNode->pNextNode;//percorre nó por nó
        }
        return currentNode->value; //retorna valor do ultimo no
    }else{
        return -1; //lista vazia
    }
}


int size(Node *startRef){ //retorna número de elementos
    int count = 0; // var de contador
    Node *currentNode = startRef; //ponteiro para o começo da lista/ o primeiro nó
    while(currentNode != NULL){ // enquanto existir nós..
        count++;
        currentNode = currentNode->pNextNode;
    }
    return count;
}

bool isEmpty(Node *startRef){ //retorna true se vazia
    return (startRef == NULL);
}

void removeFirst(Node **startRef){ //remove o primeiro nó
    if(startRef == NULL || *startRef == NULL) return;
    Node *toRemove = *startRef;
    *startRef = toRemove->pNextNode; //atualiza inicio
    free(toRemove); //libera memória
}

void removeLast(Node **startRef){ //remove o último nó
    if(startRef == NULL || *startRef == NULL) return;

    if((*startRef)->pNextNode == NULL){ //só 1 elemento
        free(*startRef);
        *startRef = NULL;
        return;
    }

    Node *currentNode = *startRef;
    while(currentNode->pNextNode->pNextNode != NULL){ //penúltimo nó
        currentNode = currentNode->pNextNode;
    }
    free(currentNode->pNextNode); //libera último
    currentNode->pNextNode = NULL; //penúltimo vira último
}

void printList(Node *startRef){
    Node *currentNode = startRef;
    printf("[");
    while(currentNode != NULL){
        printf("%d", currentNode->value);
        if(currentNode->pNextNode != NULL) printf(" -> ");
        currentNode = currentNode->pNextNode;
    }
    printf("]\n");
}

/* utilitário para liberar memória */
void freeAll(Node **startRef){
    Node *currentNode = *startRef;
    while(currentNode != NULL){
        Node *next = currentNode->pNextNode;
        free(currentNode);
        currentNode = next;
    }
    *startRef = NULL;
}

int main(){
    struct Node* lista = NULL;

    addFirst(&lista, 10);
    addFirst(&lista, 20);
    addFirst(&lista, 30);

    printf("A lista completa:\n");
    printList(lista);

    printf("tamanho: %d\n", size(lista));
    printf("isEmpty: %s\n", isEmpty(lista) ? "true" : "false");
    printf("primeiro nó: %d\n", getFirst(lista));
    printf("ultimo nó: %d\n", getLast(lista));


    printf("Removendo o primeiro:\n");
    removeFirst(&lista);//remove primeiro
    printList(lista);

    printf("Removendo o último:\n");
    removeLast(&lista);//remove último
    printList(lista);

    freeAll(&lista);//libera toda a memória

    return 0;
}
