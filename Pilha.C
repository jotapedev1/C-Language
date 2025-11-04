typedef struct Node{
    int value;
    struct Node *pNextNode;
}Node;

typedef struct Stack{
    Node *top;
    int count;
    int maxStack;
}Stack;

void push(Stack *pStack, int newValue){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Erro de alocação");
    }
    newNode->value = newValue;
    newNode->pNextNode = pStack->top;
    pStack->top = newNode;
    pStack->count++;

    printf("Elemento empilhado");
}

int pop(Stack *pStack){
    if(empty(pStack)){
        printf("Pilha vazia");
        return -1;
    }
    Node *remove = pStack->top;
    int newValue = remove->value;
    pStack->top = remove->pNextNode;
    pStack->count--;

    printf("Elemento %d removido", newValue);
    return newValue;
}

int empty(Stack *pStack){
    return(pStack->top = NULL);
}


void push(Stack *p, int value){
    Node *newNode = malloc(sizeof(Node));
    printf("");
}

int main(){
    Stack pilha;
    pilha.top = NULL;
    pilha.count = 0;
}