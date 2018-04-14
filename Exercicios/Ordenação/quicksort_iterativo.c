/*
* @Author: Julio Cesario de Paiva Leão
* @Date:   2018-03-25 11:12:59
* @Last Modified by:   julio0023
* @Last Modified time: 2018-03-25 14:36:18
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 11
	
void quickSortIterative (int arr[], int left, int right);
void printVector(int *vet);

// Inicio da função principal (main)
int main(){
	int pivo;
	int vet[MAX] = {1, 105, 34, 302, 201, 100, 65, 505, 12, 4, 5};

    printf("\nO vetor gerado e:\n");

	printVector(vet);

	printf("\nInforme o pivo do vetor acima: ");
	scanf("%d", &pivo);

    quickSortIterative (vet, 0, 10);

    printf("\nO vetor ordenado e:\n");
    printVector(vet);

	return 0;
}
// Fim da função principal


void printVector(int *vet){
	int i;
	printf("\n[ ");
	for (i = 0; i < MAX; i++){
		printf("%d ", vet[i]);
	}
	printf("]\n");
}


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
int partition(int vet[], int left, int right){
    int x = vet[right];
    int i = (left - 1), j;
 
    for (j = left; j <= right - 1; j++){
        if (vet[j] <= x){
            i++;
            swap (&vet[i], &vet[j]);
        }
    }
    swap (&vet[i + 1], &vet[right]);
    return (i + 1);
}

/* A[] --> Array to be sorted, 
   left  --> Starting index, 
   right  --> Ending index */
void quickSortIterative (int arr[], int left, int right)
{
    // Create an auxiliary stack
    int stack[ right - left + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of left and right to stack
    stack[ ++top ] = left;
    stack[ ++top ] = right;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop right and left
        right = stack[ top-- ];
        left = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int pivo = partition( arr, left, right );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( pivo-1 > left )
        {
            stack[ ++top ] = left;
            stack[ ++top ] = pivo - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( pivo+1 < right )
        {
            stack[ ++top ] = pivo + 1;
            stack[ ++top ] = right;
        }
    }
}