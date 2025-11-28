#include <stdio.h>
#include <string.h>

int main(){
    float n1, n2;

    printf("Digite o primeiro número \n");
    scanf("%f", &n1);
    printf("Digite o segundo número \n");
    scanf("%f", &n2);
    
    printf("===========RESULTADOS==========\n");
    
    printf("O resultado da soma dos números é: %.1f\n", n1+n2);
    printf("O resultado da subtração dos números é: %.1f\n", n1-n2);
    printf("O resultado da multiplicação dos números é: %.1f\n", n1*n2);
    printf("O resultado da divisão dos números é: %.2f ou %.2f \n", n1/n2, n2/n1);

}