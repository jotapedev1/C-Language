#include <stdio.h>

int main(){
    float acm, cont;
    acm = 0;
    cont = 0;

    for (int i = 13; i <= 73; i++)
    {
        acm += i;
        cont++;
    }

    printf("A soma total dos números é %.2f \n", acm);
    printf("Sua média é %.2f \n", (acm/cont));

}