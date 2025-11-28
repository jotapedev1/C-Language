    #include <stdio.h>
    int main(){
        int num, comeco, fim;
        printf("Digite um número inteiro: ");
        scanf("%i", &num);
        printf("Digite onde quer que comece: ");
        scanf("%i", &comeco);
        printf("Digite onde quer que termine: ");
        scanf("%i", &fim);
        
        for(int i = comeco; i <= fim; i++){
            float res = num*i;
            printf("%i x %i = %.1f \n", num, i, res);
        }
    }