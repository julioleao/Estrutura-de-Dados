#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

/*proponha uma forma de busca em um vetor ordenado,
tal que não seja o algoritmo de busca sequencial simples,
e nem a estratégia binária;*/

// Prototipação
int recursiveSearch(int *vector, int tam, int num);
int bubbleSort(int *vet, int tam);
void printVector(int *vet, int tam);

// Função principal
int main(){
	int *vet, tam, i, num;

	printf("Informe o tamanho do vetor: ");
	scanf(" %d", &tam);
	system(CLEAR);

	/*Aloca um espoço dinamicamente na memória 
	de acordo com o valor de entrada do usuário*/
	vet = (int*) malloc(tam * sizeof(int));

	//Funções srand e rand paraa gerar numeros aleatórios
	srand(time(NULL));

	for (i = 0; i < tam; i++){
		vet[i] = rand() % 100;
	}

	printf("O vetor gerado foi: \n");

	// Imprime o vetor preenchido
	printVector(vet, tam);

	*vet = bubbleSort(vet, tam);

	printf("O vetor ordenado foi: \n");

	// Imprime o vetor ordenado
	printVector(vet, tam);

	
	printf("Digite um numero que queira encontrar a posicao: ");
	scanf(" %d", &num);

	printf("\nO numero %d esta em ou proximo da posicao %d\n", num, recursiveSearch(vet, tam, num));

	return 0;
}

// Função de ordenação Bubble Sort
int bubbleSort(int *vet, int tam)
{    
  int i, j, aux;
 
  for(i = 0; i < tam; i++){
  	for(j = 0; j < tam -1; j++){
  		if(vet[j] > vet[j+1]){
  			aux = vet[j];
  			vet[j] = vet[j+1];
  			vet[j+1] = aux;
  		}
  	}
  }
  return *vet;
}
   
 
// Função para busca recursiiva
int recursiveSearch(int *vector, int tam, int num){
	if((num >= vector[tam-1]) && (num <= vector[tam+1])){
		return tam;
	} else {
		return recursiveSearch(vector, tam-1,num);
	}
}

// Função para imprimir o vetor preenchido
void printVector(int *vet, int tam){
	int i;
	printf("[ ");
	for (i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	printf("]\n\n");
}