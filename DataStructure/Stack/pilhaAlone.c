#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *ptrNextNode;
}Node;

typedef struct Stack{
    Node *ptrTopStack;
    int size;
}Stack;

void startStack(Stack *ptrStack){
    ptrStack->ptrTopStack = NULL;
    ptrStack->size = 0;
}

int isEmpty(Stack *ptrStack){
    return (ptrStack->ptrTopStack == NULL);
}

void push(Stack *ptrStack, int newValue){
    Node *ptrNewNode = malloc(sizeof(Node));
    if(ptrNewNode == NULL){
        printf("Memory allocation failed \n");
    }

    ptrNewNode->value = newValue;
    ptrNewNode->ptrNextNode = ptrStack->ptrTopStack;
    ptrStack->ptrTopStack = ptrNewNode;
    ptrStack->size++;

    printf("Elemento %d empilhado. \n", newValue);
}

int pop(Stack *ptrStack){
    if(isEmpty(ptrStack)){
        printf("Pilha vazia \n");
        return -1;
    }
    Node *auxRemove = ptrStack->ptrTopStack;
    int value = auxRemove->value;
    ptrStack->ptrTopStack = auxRemove->ptrNextNode;
    free(auxRemove);
    ptrStack->size--;

    return value;
}

void showStack(Stack *ptrStack){
    if(isEmpty(ptrStack)){
        printf("Pilha vazia, nada há mostrar.\n");
        return;
    }
    Node *aux = ptrStack->ptrTopStack;
    int position = ptrStack->size;
    while(aux != NULL){
        printf(" %d | \n", aux->value);
        aux = aux->ptrNextNode;
        position--;        
    }
}

int main(){
    printf("\nHello World!\n");

    Stack p;

    startStack(&p);
    push(&p, 15);
    push(&p, 30);
    push(&p, 45);
    push(&p, 60);
    showStack(&p);

    printf("\n------\n");
    pop(&p);
    pop(&p);
    showStack(&p);
}

