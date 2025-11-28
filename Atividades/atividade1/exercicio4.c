#include <stdio.h>
#include <string.h>

int main(){
    float n1, n2, n3;

    printf("Digite a primeira nota\n");
    scanf("%f", &n1);
    printf("Digite a segunda nota\n");
    scanf("%f", &n2);
    printf("Digite a terceira nota\n");
    scanf("%f", &n3);
    
    float media = (n1+n2+n3) / 3;
    printf("Sua média final é: %.2f\n", media);

    if(media >= 7){
        printf("Parabéns, vc foi aprovado\n");
    }else{
        printf("Viish, vc reprovou\n");
    }
       
}