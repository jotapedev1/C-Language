#include <stdio.h>
int main(){
    int num;
    printf("Digite um número inteiro: ");
    scanf("%i", &num);
    for(int i = 0; i <= 10; i++){
        int res = (num*i);
        if(res % 2 == 0){
            printf("%i x %i = %i \n", num, i, res);
        }
    }
}