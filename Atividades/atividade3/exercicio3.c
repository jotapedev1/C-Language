#include <stdio.h>
void soma(int a, int b){
    a = a + b;
    printf("O novo valor de A: %i\n", a);
    printf("O novo valor de B: %i\n", b);
}

int main(){
    int x,y;

    printf("Digite um número:\n");
    scanf("%i", &x);
    printf("Digite outro número:\n");
    scanf("%i", &y);

    printf("ALTERANDO OS VALORES: \n");
    soma(x,y);
    
}