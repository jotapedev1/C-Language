//Desenvolver um algoritmo que efetue a soma de todos os números ímpares que são múltiplos de três no conjunto de números de 1 até 500.
//(Dica: ímpares têm resto 1 na divisão por 2; múltiplos de 3 têm resto 0 na divisão por 3)

#include <stdio.h>
int main(){
    float acm = 0;
    for (int i = 0; i <= 500; i++)
    {
        if(i%2 == 1 && i%3 == 0){
            acm += i;
        }
    }
    printf("A dos números múltiplos de 3 e impares é: %.1f \n", acm);
}