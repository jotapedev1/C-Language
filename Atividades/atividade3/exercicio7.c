#include <stdio.h>

int ordenar(int vetor[], int tamanho){
    int anterior = vetor[0];
    if (anterior == vetor[0+1])
    {
        return 1;
    }else{
        for (int i = 0; i < tamanho; i++)
        {       
            for (int j = 0; j < tamanho - 1; j++)
            {
                if (vetor[j] > vetor[j+1])
                {
                    int troca = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = troca;
                }   
            }
        }
        return 0;
    }
}

void exibir(int vetor[], int tamanho){
    for (int  i = 0; i < tamanho; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int vetor[3];
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite um número\n");
        scanf("%i", &vetor[i]);
    }

    int resultado = ordenar(vetor, tamanho);

    printf("\nResultado da chamada da função: %i \n", resultado);
    printf("NÚMEROS ORDENADOS: \n");

    exibir(vetor, tamanho);
}
