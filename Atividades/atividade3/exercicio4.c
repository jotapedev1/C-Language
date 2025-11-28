#include <stdio.h>
int main(){
    
    float vet[10];

    printf("Endereços dos elementos em uma array \n");
    
    for(int i = 0; i < 10; i++){
        float *pv = &vet[i];
        printf("Index do array %i: %p\n", i, pv);
    }
}