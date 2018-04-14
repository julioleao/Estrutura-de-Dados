/**
*
*
 Julio Cesario de Paiva Leão
 RA: 1916033
 Engenharia de Software
 Estrutura de Dados - 2018/01

 EXERCICIO
 crie um TAD que é uma lista encadeada;
 você deve representar uma série, exemplo: Lost, Dexter, Breaking Bad, Game of Thrones, Walking Dead, Demolidor, Simpsons, etc...;
 cada nó deve ter os seguintes campos:
 > nome;
 > duracao_minutos;
 > proximo_episodio (que é o ponteiro de controle da sua lista);

 você deve criar um menu, no qual seja possível realizar as operações:
	iniciar lista;
	inserir episódio;
	imprimir normal;
	imprimir recursivamente;
	imprimir recursivamente invertido;
	remover episódio por nome;
	buscar episódio por nome;
	buscar episódio por duração;
	liberar a lista;
*
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myseries.h" //TAD criado com todas as funções e listas encadeadas

// Prototipação
int menu(int *pt);


/*Função principal*/
int main(){
	int op = -1, min;
	Series *list;
	char name[50];

	

	while(op != 0){
		system(CLEAR);
		switch(menu(&op)){

			case 1:
				// Lista iniciada em NULL
				list = start();
				printf("\n+--------------------+\n");
				printf("|   LISTA INICIADA   |\n");
				printf("+--------------------+\n");
				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL); // Limpa o buffer do teclado
				getchar();
				break;
			case 2:
				/*Inserir uma nova serie e sua duração, em seguida,
				passar como parametro para a função insert*/
				printf("Informe o nome do episodio............: ");
				scanf("%s", name);
				printf("Informe a duracao (min) do episodio...: ");
				scanf("%d", &min);
				list = insert(list, name, min);
				break;
			case 3:
				// Imprimi os valores da lista na tela
				printList(list);
				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 4:
				/*Imprimi todas as séries cadastradas de forma recursiva*/
				printf("+---------------------------------->\n");
				printRecursive(list);

				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 5:
				/*Imprimi todas as séries cadastradas de forma recursiva invertida*/
			 	printf("+---------------------------------->\n");
				printInvertedRecursive(list);

				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 6:
				/*Informar o nome do episódio para que seja removido*/
				printf("Informe o nome do episodio............: ");
				scanf("%s", name);
				list = removeList(list, name);
				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 7:
				/*Realizar a busca pelo NOME da serie
				caso o retorno da função searchName seja diferente
				de NULL, imprima os valores.*/
				printf("Informe o nome da serie que deseja buscar: ");
				scanf("%s", name);
				if((searchName(list,name)) != NULL){
					printf("+---------------------------------->\n");
            		printf("Nome.....: %s", searchName(list,name)->name);
            		printf("\nDuracao..: %d min\n", searchName(list,name)->min);
           			printf("+---------------------------------->\n");
				}
				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 8:
				/*Realizar a busca pela DURAÇÃO da serie
				caso o retorno da função searchMin seja diferente
				de NULL, imprima os valores.*/
				printf("Informe a duracao (min) da serie que deseja buscar: ");
				scanf("%d", &min);
				if((searchMin(list,min)) != NULL){
					printf("+---------------------------------->\n");
            		printf("Nome.....: %s", searchMin(list,min)->name);
            		printf("\nDuracao..: %d min\n", searchMin(list,min)->min);
           			printf("+---------------------------------->\n");
				}
				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 9:
				/*Apaga todos os elementos da lista, liberando o ponteiro list
				e em seguida voltando ao ponto inicial.*/
				printf("LIBERANDO LISTA...\n\n");

				freeList(list);
				list = start();

				printf("\n+---------------------+\n");
				printf("|   LISTA LIBERADA!   |\n");
				printf("+---------------------+\n");

				printf("\nPressione ENTER para voltar... ");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 0:
				/*Mensagem de despedida após encerrar programa*/
				printf("\n+-------------------------------------+\n");
				printf("|   VALEU, FALOU E ATE....ATE MAIS.   |\n");
				printf("+-------------------------------------+\n\n");
				break;
			default:
				/*Mensagem de erro após digitar algum comando inválido*/
				printf("\n+--------------------+\n");
				printf("|   OPCAO INVALIDA   |\n");
				printf("+--------------------+\n");
				printf("\nPressione ENTER para continuar... ");
				setbuf(stdin,NULL);
				getchar();
				break;

		}
	}

	return 0;
}

// Função menu principal
int menu(int *opt){
	
	printf("+------------------------------------------+\n");
	printf("| [1] - Iniciar lista                      |\n");
	printf("| [2] - Inserir episodio                   |\n");
	printf("| [3] - Imprimir normal                    |\n");
	printf("| [4] - Imprimir recursivamente            |\n");
	printf("| [5] - Imprimir recursivamente invertido  |\n");
	printf("| [6] - Remover episodio por nome          |\n");
	printf("| [7] - Buscar episodio por nome           |\n");
	printf("| [8] - Buscar episodio por duracao        |\n");
	printf("| [9] - Liberar a lista                    |\n");
	printf("| [0] - Sair                               |\n");
	printf("+------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}