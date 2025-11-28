#include <stdio.h>

int main()
{
    int a = 42;
    int *pa = &a;
    float b = 4.20;
    float *pb = &b;
    char c = 'j';
    char *pc = &c;
    
    printf("Ponteiros apontando para as váriaveis: %i , %.2f , %c\n", *pa,*pb,*pc);
    //colocando novos valores
    *pa = 07;
    *pb = 7.7;
    *pc = 'i';
    //imprimindo novos valores
    printf("novos valores dos ponteiro: %i , %.2f , %c\n", *pa,*pb,*pc);
    printf("prova que alterou as variaveis: %i , %.2f , %c\n", a,b,c);
  
    return 0;
}