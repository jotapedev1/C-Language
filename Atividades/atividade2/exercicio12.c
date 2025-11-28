#include <stdio.h>

int main() {
    int num;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    do {
        printf("Digite um numero (negativo para parar): ");
        scanf("%d", &num);

        if (num >= 0 && num <= 25) {
            c1++;
        } else if (num >= 26 && num <= 50) {
            c2++;
        } else if (num >= 51 && num <= 75) {
            c3++;
        } else if (num >= 76 && num <= 100) {
            c4++;
        }

    } while (num >= 0);

    printf("Quantidade no intervalo [0-25]: %d\n", c1);
    printf("Quantidade no intervalo [26-50]: %d\n", c2);
    printf("Quantidade no intervalo [51-75]: %d\n", c3);
    printf("Quantidade no intervalo [76-100]: %d\n", c4);

    return 0;
}
