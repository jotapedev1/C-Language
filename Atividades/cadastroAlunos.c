#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
}Aluno;

int main() {
    Aluno *pAluno = NULL;
    int capacidade = 2;
    int qtd = 0;
    char resp;

    pAluno = (Aluno *) malloc(capacidade * sizeof(Aluno));
    if (pAluno == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    do {
        if (qtd == capacidade) {
            capacidade *= 2;
            Aluno *tmp = (Aluno *) realloc(pAluno, capacidade * sizeof(Aluno));
            if (tmp == NULL) {
                printf("Erro de alocacao!\n");
                free(pAluno);
                return 1;
            }
            pAluno = tmp;
        }

        printf("Escreva o nome do %i aluno \n", (qtd+1));
        scanf("%49s", pAluno[qtd].nome);
        printf("Escreva a idade do %i aluno\n", (qtd+1));
        scanf("%d", &pAluno[qtd].idade);
        printf("Qual a nota desse aluno? \n");
        scanf("%f", &pAluno[qtd].nota);

        printf("Deseja cadastrar outro aluno? (s/n):\n");
        scanf(" %c", &resp);

        qtd++;
    } while (resp == 's' || resp == 'S');

    printf("\nAlunos cadastrados:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s, Idade: %d, Nota: %.2f\n", i+1, pAluno[i].nome, pAluno[i].idade, pAluno[i].nota);
    }

    free(pAluno);
    return 0;
}
