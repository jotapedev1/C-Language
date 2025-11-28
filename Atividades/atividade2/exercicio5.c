#include <stdio.h>
int main(){
    int num;
    printf("Digite um número inteiro: ");
    scanf("%i", &num);
    for(int i = 0; i <= 10; i++){
        float res = num*i;
        printf("%i x %i = %.1f \n", num, i, res);
    }
}