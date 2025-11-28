#include <stdio.h>
#include <string.h>

int main(){
    float n1, n2;
    int escolha;

    printf("Digite o primeiro número \n");
    scanf("%f", &n1);
    printf("Digite o segundo número \n");
    scanf("%f", &n2);
    
    printf("===========Selecione a operação==========\n");
    
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    scanf("%i", &escolha);

    switch(escolha){
        case 1:
            printf("O resultado da soma dos números é: %.1f\n", n1+n2);
            break;
        case 2:
            printf("O resultado da subtração dos números é: %.1f\n", n1-n2);
            break;
        case 3:
            printf("O resultado da multiplicação dos números é: %.1f\n", n1*n2);
            break;
        case 4:
            printf("O resultado da divisão dos números é: %.2f ou %.2f \n", n1/n2, n2/n1);
            break;
        default:
            printf("Escolha inválida");
            break;
    }

}