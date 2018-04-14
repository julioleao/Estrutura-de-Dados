#include <stdio.h>
#include <stdlib.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

int recursiveSum (int v[], int n);

int main() {
	int vector[] = {10, 3, 5, 2, 15}, n = 5, result;

	result = recursiveSum (vector, n);
	
	printf("\nO resultado da soma e: %d\n\n", result);
	printf("Pressione alguma tecla para continuar...\n");
	getchar();
	system(CLEAR);
    return 0;
}

/*
 *
	Função para soma recursiva no vetor
	é passado como parâmetro o vector e n,
	sendo n o indice de vector.
	A condição de parada seria quando n for igual a 0,
	ou seja, assim que o indice n chegar na posição 0
	do vetor, retorne a soma de todos os elementos
	dentro desse vetor.
 *
 */

int recursiveSum (int vector[], int n) { 
	int sum = 0;
	if (n == 0)
	  return sum;
	else {
		sum = recursiveSum (vector, n-1);
		return sum + vector[n-1];
	}
}