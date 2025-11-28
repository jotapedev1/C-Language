#include <stdio.h>

int main(){
    int vet[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Insira um número\n");
        scanf("%i", &vet[i]);
    }
    printf("O dobro dos números são:\n");
    for (int i = 0; i < 5; i++)
    {
        int *pv = &vet[i];
        int dobro = 2*(*pv);
        printf("O dobro do index %i e: %i \n", i, dobro);
    }
    
    
}