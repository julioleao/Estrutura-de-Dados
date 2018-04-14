#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void printData(int *sort, int tam);

int cont = 0;

int main(){
	int *vet;
	int *sort;
	int tam, i, menor, maior, ini; 

	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);


	vet = (int*) malloc(tam * sizeof(int));
	sort = (int*) malloc(tam * sizeof(int));

	if(vet == NULL || sort == NULL){
		printf("ERRO NA ALOCACAO DE MEMORIA!\n");
		exit(1);
	}
	

	//vetAloc(tam, vet);
	srand(time(NULL));
	for (i = 0; i < tam; i++){
		vet[i] = rand() % 100;
	}

	printf("O vetor gerado foi: \n");
	printf("[ ");
	for (i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	/*system(CLEAR);*/
	ini = 0;
	while(ini < tam){
		for (i = ini; i < tam-1; i++){
			if(vet[ini] < vet[i+1]){
				sort[ini] = vet[ini];
			} 
			cont++;
		}
		printf("%d ", sort[ini]);
		ini++;
	}
	//free(vet);
	printf("\n\nVETOR ORDENADO\n[ ");
	for (int i = 0; i < tam; ++i)
	{
		printf("%d ", sort[i]);
	}
	printf("]\nComparaçoes: %d\n", cont);
	printData(sort, tam);

	return 0;
}

void printData(int *sort, int tam){
	int i;
	printf("\n\nVETOR ORDENADO\n[ ");
	for (int i = 0; i < tam; ++i)
	{
		printf("%d ", sort[i]);
	}
	printf("]\nComparaçoes: %d\n", cont);
}