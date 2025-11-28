#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int x = 0;
    
    char nomes[100][100];
    float notas[100], acm;
    int i = 0;

    while(x<10){
        printf("Qual o nome do aluno? \n");
        fgets(nomes[x], 100, stdin);
        nomes[x][strcspn(nomes[x], "\n")] = '\0'; // remove o '\n'

        printf("Qual a nota?\n");
        scanf("%f", &notas[x]);
        getchar(); // limpa o ENTER
        x++;
    }
    while(i < x){
        acm += notas[i];
        i++;
    }

    float media = acm/x; 
    for(int i = 0; i < x; i++){
        printf("Nome: %s\n", nomes[i]);
        printf("Nota: %.1f\n", notas[i]);
    }
    
    printf("A média da turma é: %.1f", media);
}