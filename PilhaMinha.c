#include <stdio.h>
#include <stdlib.h>

typedef struct prato{
    int valor;
    struct prato *proximoPrato;
}prato;

prato *top = NULL;

void push(int novoValor){
    prato *novoPrato = malloc(sizeof(prato));
    if (novoPrato == NULL){
        printf("Alocação de memória falhou\n");
        return;
    }
    novoPrato->valor = novoValor;
    novoPrato->proximoPrato = top;
    top = novoPrato;

    printf("Elemento inserido com sucesso\n");
}

void pop(){
    if (top == NULL){
        printf("A pilha está vazia\n");
    }
    prato *temporario;
    temporario = top;
    top = temporario->proximoPrato;

    printf("Primeiro elemento da pilha: %d jogado fora\n", temporario->valor);
    free(temporario);//jogando o bagui fora
}

void topo(){
    if(top == NULL){
        printf("Pilha vazia\n");
    }
    printf("O topo da lista é: %d\n", top->valor);
}
int tamanho(){
    if(top == NULL){
        printf("Pilha vazia\n");
    }
    int count = 0;
    prato *temporario = top;
    while(temporario != NULL){
        count++;
        temporario = temporario->proximoPrato;
    }
    return count;
}
int soma(){
    if(top == NULL){
        printf("Pilha vazia\n");
    }
    int acm = 0;
    prato *temporario = top;
    while(temporario != NULL){
        acm += temporario->valor;
        temporario = temporario->proximoPrato;
    }
    return acm;
}

int maior(){
    if(top == NULL){
        printf("Pilha vazia\n");
        return 0;
    }
    int maior = top->valor;
    prato *temporario = top->proximoPrato;
    while(temporario != NULL){
        if(temporario->valor > maior){
            maior = temporario->valor;
        }
        temporario = temporario->proximoPrato;
    }
    return maior;
}

void imprimir(){
    if(top == NULL){
        printf("Tem nada aqui carai\n");
    }
    prato *temporario;
    temporario = top;
    while(temporario != NULL){
        printf("%d -> ", temporario->valor);
        temporario = temporario->proximoPrato;
    }
}

int main(){
    int opcao, num;

    push(4);
    push(5);
    push(6);

    do{
        printf("\n \nESCOLHA\n 1 - Inserir numero\n 2 - Tirar elemento\n 3 - Imprimir Lista\n 4 - Ver topo da lista\n 10 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Digite um número para adicionar\n");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("Excluindo...\n");
                pop();
                break;
            case 3:
                printf("Se liga na sua pilha:\n ");
                imprimir();
                break;
            case 4:
                topo();
                break;
            case 5:
                printf("A pilha tem %d elementos\n", tamanho());
                break;
            case 6:
                printf("A soma de elementos da pilha é %d \n", soma());
                break;
            case 7:
                printf("O maior elemento da pilha é %d \n", maior());
                break;                
            case 10:
                printf("Saindo...");
                break;
            default:
                printf("Escolha inválida\n");
                break;
        }
    }while(opcao != 10);
}