#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *pNextNode;
} Node;

Node* creatingNode(int newValue){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->value = newValue;
    newNode->pNextNode = NULL;
    return newNode;
}

void addFirst(struct Node **startRef, int newValue){//ponteiro apontando para o ponteiro de Node
    Node *newNode = creatingNode(newValue);//alocando memória e settando next como NULL
    newNode->pNextNode = *startRef;
    *startRef = newNode;
}
void getFirst(struct Node *startRef){
    if(startRef != NULL){
        Node *currentNode = startRef;
        return currentNode->value;
    }else
    {
        return 1;
    }
}

void addLast(struct Node **startRef, int newValue){ //ponteiro apontando para o ponteiro de Node
    Node *newNode = creatingNode(newValue); //criando novo nó, alocando memoria, settando próximo como nulo
    if(startRef == NULL){
        *startRef = newNode; // se meu próximo estiver vazio, este se torna o meu próximo
        return;
    }
    Node *currentNode = *startRef; //criando ponteiro que aponta para primeiro nó da lista
    while (currentNode->pNextNode != NULL)//enquanto meu próximo nó não for nulo...
    {
        currentNode = currentNode->pNextNode;//percorre nó por nó
    }
    currentNode->pNextNode = newNode;//saindo do loop, pq encontramos o último nó
}

int getLast(struct Node *startRef){
    if(startRef != NULL){
        Node *currentNode = startRef; //criando ponteiro que aponta para primeiro nó da lista
        while (currentNode->pNextNode != NULL)//enquanto meu próximo nó não for nulo...
        {
            currentNode = currentNode->pNextNode;//percorre nó por nó
        }
        return currentNode->value;
    }else
    {
        return 1;
    }
}

int main(){
    struct Node* lista = NULL;

    addFirst(&lista, 10);
    addFirst(&lista, 20);
    addFirst(&lista, 30);

    
    return 0;
}
