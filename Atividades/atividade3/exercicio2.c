#include <stdio.h>

int main()
{
	int a = 42;
	int *pa = &a;
	int b = 44;
	int *pb = &b;
	int endA = pa;
	int endB = pb;
	int valorA = *pa;
	int valorB = *pb;
	
	

	int maior = endA;
	if(endB > maior) {
		maior = endB;
	}

	int maiorValor = valorA;
	if(valorB > maiorValor) {
		maiorValor = valorB;
	}


	printf("Endereço de memórias: %i e %i \n", pa, pb);
	printf("O maior endereço é o: %i\n", maior);


	printf("Valores armazenados nos ponteiros: %i e %i\n", *pa, *pb);
    printf("O maior valor é: %i\n", maiorValor);

	return 0;
}