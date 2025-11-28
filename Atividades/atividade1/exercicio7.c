#include <stdio.h>

int main(){
    float salario, desconto;
    printf("Informe seu salário\n");
    scanf("%f", &salario);

    if (salario < 2260){
        printf("Você está isento de I.R\n");
    }else if (salario < 2827){
        desconto = salario * (7.5/100);
        salario -= desconto;
        printf("Salário atual com desconto de 7.5/100 é de: %f\n", salario);
    }else if(salario < 3750){
        desconto = salario * (15/100);
        salario -= desconto;
        printf("Salário atual com desconto de 15/100 é de: %f\n", salario);
    }else if(salario < 4665){
        desconto = salario * (22.5/100);
        salario -= desconto;
        printf("Salário atual com desconto de 22.5/100 é de: %f\n", salario);
    }else{
        desconto = salario * (27.5/100);
        salario -= desconto;
        printf("Salário atual com desconto de 27.5/100 é de: %f\n", salario);
    }
}