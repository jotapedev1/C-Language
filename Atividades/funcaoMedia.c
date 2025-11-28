#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float media(float a, float b, float c){
        float resultado = (a + b + c) / 3;
        return resultado;
    }


int main() {

    float n1, n2, n3;

    printf("digite um número ");
    scanf("%f", &n1);
    printf("digite outro número ");
    scanf("%f", &n2);
    printf("digite outro número ");
    scanf("%f", &n3);
    
    float resposta = media(n1, n2, n3);
    printf("A média dos 3 é %.2f", resposta);
}