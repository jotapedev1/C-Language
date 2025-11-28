#include <stdio.h>
int main(){
    float n, acm;
    int escolha;
    int x = 0;
    
    while (escolha != 0)
    {    
        printf("AVISO: NÃO RESPONDA COM LETRAS!!!\n");
        printf("Quer continuar? [1] sim [0] não\n");
        scanf("%i", &escolha);
        if(escolha == 0){
            break;
        }

        printf("Digite o preço do %i º item \n", (x+1));
        scanf("%f", &n);
        acm +=n;
        x++;
    }
    printf("O total da compra é de: R$ %.2f \n", acm);
}