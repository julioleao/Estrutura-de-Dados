#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

typedef struct reg{
	char name[20];
	int age;
}reg;


int menu();
void insertData(reg people[]);
void printData(reg people[]);
void bubbleC(reg people[], int index);
void bubbleD(reg people[], int index);
void selectionC(reg people[], int index);
void selectionD(reg people[], int index);
void insertionC(reg people[], int index);
void insertionD(reg people[], int index);
int ordenation();

int main(int argc, char const *argv[]){

	reg people[7];
	int index = 7, op = 1;

	insertData(people);
	
	do{
		switch(menu()){
			case 1:
				switch (ordenation()){
					case 1: 
						bubbleC(people, index);
						break;
					case 2:
						bubbleD(people, index);
						break;
					default:
						printf("OPCAO INVALIDA!\n");
						break;
				}
				
				break;
			case 2:
				switch (ordenation()){
					case 1: 
						selectionC(people, index);
						break;
					case 2:
						selectionD(people, index);
						break;
					default:
						printf("OPCAO INVALIDA!\n");
						break;
				}
				break;
			case 3:
				switch (ordenation()){
					case 1: 
						insertionC(people, index);
						break;
					case 2:
						insertionD(people, index);
						break;
					default:
						printf("OPCAO INVALIDA!\n");
						break;
				}
				break;
			case 4:
				op = 0;
				break;
			default:
				printf("OPCAO INVALIDA!\n");
				break;
		}
	} while(op != 0);
	
	return 0;
}

void insertData(reg people[]){

	strcpy(people[0].name,"Jessica  "); 
	strcpy(people[1].name,"Lucas    "); 
	strcpy(people[2].name,"Joseff   "); 
	strcpy(people[3].name,"Johnny   "); 
	strcpy(people[4].name,"Albert   "); 
	strcpy(people[5].name,"Bernard  "); 
	strcpy(people[6].name,"Guilherme");

	people[0].age = 22;
	people[1].age = 24;
	people[2].age = 22;
	people[3].age = 38;
	people[4].age = 20;
	people[5].age = 18;
	people[6].age = 31;
}

int menu(){
	int op;
	printf("[1] BubbleSort\n");
	printf("[2] SelectionSort\n");
	printf("[3] InsectionSort\n");
	printf("[4] Sair\n");
	scanf("%d", &op);
	system(CLEAR);
	return op;
}

void printData(reg people[]){
	printf("Nome:       |  Idade: \n");
	printf("----------------------\n");
	for (int i = 0; i < 7; ++i)
	{
		printf("%s   |	%d\n", people[i].name, people[i].age);
	}
	getchar();
	getchar();
	system(CLEAR);

}

void bubbleC(reg people[], int index){
	int i, j;
	reg aux;

	for(i = 0; i < index; i++){
		for (int j = 0; j < index -1; j++)
		{
			if(people[j].age > people[j+1].age){
				aux = people[j];
				people[j] = people [j+1];
				people[j+1] = aux;
			}
		}
	}
	printData(people);
}

void bubbleD(reg people[], int index){
	int i, j;
	reg aux;

	for(i = 0; i < index; i++){
		for (int j = 0; j < index -1; j++)
		{
			if(people[j].age < people[j+1].age){
				aux = people[j];
				people[j] = people [j+1];
				people[j+1] = aux;
			}
		}
	}
	printData(people);
}

int ordenation(){
	int opt;
	printf("[1] Crescente\n");
	printf("[2] Decrescente\n");
	scanf("%d", &opt);
	system(CLEAR);

	return opt;
}

void selectionC(reg people[], int index){
	int i, j, min;
	reg aux;

	for(i = 0; i < index; i++){
		min = i;
		for (j = i+1; j < index -1; j++)
		{
			if(people[j].age < people[min].age){
				aux = people[j];
				people[j] = people [min];
				people[min] = aux;
			}
		}
	}
	printData(people);
}

void selectionD(reg people[], int index){
	int i, j, max;
	reg aux;

	for(i = 0; i < index -1; i++){
		max = i;
		for (j = i+1; j < index; j++)
		{
			if(people[j].age > people[max].age){
				aux = people[j];
				people[j] = people [max];
				people[max] = aux;
			}
		}
	}
	printData(people);
}

void insertionC(reg people[], int index){
	int i, j;
	reg aux;

	for (i = 1; i < index; i++)
	{
		aux = people[i];
		for(j = i; (j > 0) && (aux.age < people[j - 1].age); j--){
			people[j] = people[j-1];
		}
		people[j] = aux;
		
	}
	printData(people);
}

void insertionD(reg people[], int index){
	int i, j;
	reg aux;

	for (i = 1; i < index; i++)
	{
		aux = people[i];
		for(j = i; (j > 0) && (aux.age > people[j - 1].age); j--){
			people[j] = people[j-1];
		}
		people[j] = aux;
		
	}
	printData(people);
}