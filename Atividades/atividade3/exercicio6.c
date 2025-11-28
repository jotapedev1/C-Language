#include <stdio.h>

int main(){
    int vet[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Insira um número\n");
        scanf("%i", &vet[i]);
    }
    printf("Se o valor é par, este é seu endereco:\n");
    for (int i = 0; i < 5; i++)
    {
        int *pv = &vet[i];
        if (*pv % 2 == 0){
            printf("O valor %i tem o endereco de %p\n", *pv, pv);
        }
    }
    
    
}