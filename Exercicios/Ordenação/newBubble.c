/*
 *
 Nome: Julio Cesario de Paiva Leão
 RA: 1916033
 Engenharia de Software 2018/01
 Estrutura de Dados
 *
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Prototipação
void printData(int *vet, int tam);
void sort(int *vet, int tam);


// Função principal
int main(){
	int *vet, tam, i;

	/*
	Pedindo ao usuário para informar o tamanho do vetor
	a ser alocado.
	*/
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	system(CLEAR);

	/*
	onteiro *vet é alocado dinamicamente com a função
	malloc, a partir do tamanho informado pelo usuário.
	*/
	vet = (int*) malloc(tam * sizeof(int));

	// Função srand para que não haja numeros repetidos

	srand(time(NULL));

	for (i = 0; i < tam; i++){
		// Função rand gerará numeros inteiros aleatórios de 0 a 100
		vet[i] = rand() % 100;
	}


	// Mostra na tela o vetor gerado
	printf("O vetor gerado foi: \n");
	printData(vet, tam);

	// Realiza a ordenação em ordem crescente
	sort(vet, tam);

	// Mostra o vetor ordenado
	printf("\nO vetor ordenado foi: \n\n");
	printData(vet, tam);

	return 0;

}

// Função para ordenação do vetor *vet
void sort(int *vet, int tam){
	int aux, i, j, mid = tam/2;

	while(mid > 0){
		i = mid;
		while(i < tam){
			aux = vet[i];
			j = i;
			while(j >= mid && aux < vet[j-mid]){
				vet[j] = vet[j-mid];
				j = j- mid;
			}
			vet[j] = aux;
			i++;
		}
		printf("%d", mid);
		mid = mid/2;
	}

}

// Função para immprimir o vetor na tela
void printData(int *vet, int tam){
	int i;
	printf("[ ");
	for (i = 0; i < tam; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("]\n\n");
}