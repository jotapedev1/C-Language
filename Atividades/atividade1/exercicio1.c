#include <stdio.h>
#include <string.h>

int main(){
    int idade;
    printf("Quantos anos você tem? ");
    scanf("%i", &idade);
    if (idade > 18)
    {
        printf("Você atingiu a maioridade\n");
    }
    else{
        printf("Você ainda não atingiu a maioridade\n");
    }

}