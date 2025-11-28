#include <stdio.h>
#include <string.h>

int main(){
    char username[40], senha[40], tentativaSenha[40], tentativaUsername[40];

    printf("Cadastre um nome de usuário \n");
    scanf("%s", username);
    printf("Cadastre uma senha \n");
    scanf("%s", senha);

    system("clear"); //limpatela

    printf("DADOS CADASTRADADOS COM SUCESSO!\n");
    printf("Hora de testar sua memória!");

    printf("Insira seu nome de usuário \n");
    scanf("%s", tentativaUsername);
    getchar(); // Limpa o '\n' deixado no buffer

    printf("Insira seu nome de usuário \n");
    scanf("%s", tentativaSenha);

    int verificaUser = strcmp(tentativaUsername, username);
    int verificaSenha = strcmp(tentativaSenha, senha);

    if (verificaUser == 0 && verificaSenha == 0){
        printf("Acesso concedido\n");
    }else{
    printf("Dados incorretos, ACESSO NEGADO\n");
    }
}