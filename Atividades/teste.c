#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
//to doido
{
int i = 0;
int x = 0; //x = número de itens
//ponteiro para apontar para o local da memória
char nomeItem[100][100];
char descricao[100][100];
int quantidade[x];
int escolha;
escolha = 0;

do
{
    
    printf("--MENU DO SISTEMA-- \n");
    printf("[1] Cadastrar item \n");
    printf("[2] Listar itens \n");
    printf("[3] Excluir itens \n");
    printf("[4] Sair \n");
    scanf("%i", &escolha);
    getchar(); // Limpa o '\n' deixado no buffer

    switch(escolha){
        case 1:                
            x++;
            
            
                printf("Qual o item quer Cadastrar? \n");
                fgets(nomeItem[x], 100, stdin); // lê com espaços
                nomeItem[x][strcspn(nomeItem[x], "\n")] = '\0'; // remove o \n do final

                printf("Descrição do item: \n");
                fgets(descricao[x], 100, stdin);
                descricao[x][strcspn(descricao[x], "\n")] = '\0'; // remove o \n

                printf("Quantidade: \n");
                scanf("%d", &quantidade[x]);
                getchar(); // limpa o ENTER após scanf

                x++; // incrementa número de itens
                break;

            
        case 2:
           //printando o itens dos arrays em loop     
            for (i = 0; i < x; i++) //enquanto menor q x(número de itens)
            {
                    printf("Item %d: %s\n", i + 1, nomeItem[i]);
                    printf("Descrição: %s\n", descricao[i]);
                    printf("Quantidade: %d\n\n", quantidade[i]);
            }                               
            break;
        case 3:
            printf("Indisponível no momento \n");
            break;
        case 4:
            printf("Saindo \n");
            break;
        default:
            printf("Escolha incorreta \n");
            break;
    }
} while (escolha != 4);

return 0;
}
