#include <stdio.h>

int main() {
    int digito;

    printf("Digite o último número da sua placa\n");
    scanf("%i", &digito);

    if (digito == 1 || digito == 2) {
        printf("Segunda-feira\n");
    } else if (digito == 3 || digito == 4) {
        printf("Terça-feira\n");
    } else if (digito == 5 || digito == 6) {
        printf("Quarta-feira\n");
    } else if (digito == 7 || digito == 8) {
        printf("Quinta-feira\n");
    } else if (digito == 9 || digito == 0) {
        printf("Sexta-feira\n");
    } else {
        printf("Número inválido!\n");
    }

    return 0;
}
