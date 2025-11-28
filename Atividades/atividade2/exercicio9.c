#include <stdio.h>

int main() {
    int escolha, maior = 0, menor = 0, idade;
    int i = 0;

    do {    
        printf("AVISO: NÃO RESPONDA COM LETRAS!!!\n");
        printf("Quer continuar? [1] sim [0] não\n");
        scanf("%i", &escolha);

        if (escolha == 0) {
            break;
        }

        printf("Insira a idade da %iº pessoa: ", (i+1));
        scanf("%i", &idade);

        if (i == 0) {  
            maior = idade;
            menor = idade;
        } else {
            if (idade > maior) {
                maior = idade;
            }
            if (idade < menor) {
                menor = idade;
            }
        }

        i++;
        
    } while (escolha != 0);

    printf("A maior idade é: %i \n", maior);
    printf("A menor idade é: %i \n", menor);
}
