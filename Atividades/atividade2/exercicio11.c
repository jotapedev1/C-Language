#include <stdio.h>

int main() {
    int filhos, total_filhos = 0, pessoas = 0;
    float salario, soma_salario = 0, maior_salario = 0;
    int ate_100 = 0;
    char continuar;

    do {
        printf("Digite o salario: ");
        scanf("%f", &salario);
        printf("Digite o numero de filhos: ");
        scanf("%d", &filhos);

        soma_salario = soma_salario + salario;
        total_filhos = total_filhos + filhos;
        pessoas++;

        if (salario > maior_salario) {
            maior_salario = salario;
        }

        if (salario <= 100) {
            ate_100++;
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    if (pessoas > 0) {
        printf("Media de salario: %.2f\n", soma_salario / pessoas);
        printf("Media de filhos: %.2f\n", (float) total_filhos / pessoas);
        printf("Maior salario: %.2f\n", maior_salario);
        printf("Percentual de pessoas com salario ate 100: %.2f%%\n", (ate_100 * 100.0) / pessoas);
    } else {
        printf("Nenhum dado informado.\n");
    }

    return 0;
}
