#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main() {

    float a, b, c;

    printf("digite um número ");
    scanf("%f", &a);
    printf("digite outro número ");
    scanf("%f", &b);
    printf("digite outro número ");
    scanf("%f", &c);

 if (a == b && b == c) {
        printf("Os números são iguais\n");
    } else {
        float menor = a;
        if (b < menor) menor = b;
        if (c < menor) menor = c;
        printf("O menor número é %.2f\n", menor);
    }


}