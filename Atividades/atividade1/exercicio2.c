#include <stdio.h>
#include <string.h>

int main(){
    float peso, altura;

    printf("Quantos quilos você pesa? \n");
    scanf("%f", &peso);
    printf("Qual sua altura? (exemplo 1.65) \n");
    scanf("%f", &altura);
    
    float imc = (peso / (altura*altura));
    printf("SEU IMC É %.2f \n", imc);
    if (imc < 18.5){
        printf("Você está abaixo do peso\n");
    }
    else if(imc < 24.5){
        printf("Você está com peso normal\n");
    }else if(imc < 29.9){
        printf("Você está com excesso de peso\n");
    }else if(imc < 35){
        printf("Você está obeso\n");
    }else{
        printf("Você está EXTREMAMENTE obeso\n");
    }

}