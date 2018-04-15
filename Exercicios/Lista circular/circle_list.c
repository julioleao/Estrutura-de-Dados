/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	
	Nós falamos e definimos TADs, entretanto nossas implementações (por questões didáticas) não separam nossos códigos como TADs;
	Implemente os TADs para as seguintes estruturas:
		> lista simplesmente encadeada;
		> lista duplamente encadeada;
		> lista circular;
		> implemente todos as operações disponíveis nos arquivos de exemplos

	Implemente ainda todas as operações adicionais (para cada TAD):
		> encontrar o maior elemento;
		> encontrar o menor elemento;
		> inserir de forma ordenada;
		> inserir no fim de uma lista;
		> remover do início de uma lista;
		> remover do fim de uma lista;

 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list.h"
#include "default.h"
#include "unique_list.h"
#include "circle_list.h"

// Prototipação
int menu(int *opt);

// Variáveis globais
Circle *head = NULL;

// Funcao principal
int main(){
	// Variavel para controlar laco do menu
	int opt, opt1 = 1;

	Counter *list2 = startDouble();
	Unique *list1 = startUnique();
	
	
	// Menu principal
	while (opt1 != 0) {
		opt = 1;
		switch (menu2(&opt1)) {
			case 1:

				while(opt != 0){
					system(CLEAR);
					printf("+-------------------------------------------------------+\n");
					printf("|             LISTA SIMPLESMENTE ENCADEADA              |\n");
					switch(menu(&opt)){
						case 1:
							list1 = orderedInsertUnique(list1);
							break;
						case 2:
							list1 = insertToEndUnique(list1);
							break;
						case 3:
							searchBiggestUnique(list1);
							pause();
							break;
						case 4:
							searchSmallerUnique(list1);
							pause();
							break;
						case 5:
							list1 = removeAtStartUnique(list1);
							pause();
							break;
						case 6:
							list1 = removeAtEndUnique(list1);
							pause();
							break;
						case 7:
							printListUnique(list1);
							pause();
							break;
						case 0:
							break;
						default:
							errorMsg();
							pause();
							break;
					}
				}
				break;
			case 2:

				while(opt != 0){
					system(CLEAR);
					printf("+-------------------------------------------------------+\n");
					printf("|              LISTA DUPLAMENTE ENCADEADA               |\n");
					switch(menu(&opt)){
						case 1:
							list2 = orderedInsertDouble(list2);
							break;
						case 2:
							list2 = insertToEndDouble(list2);
							break;
						case 3:
							searchBiggestDouble(list2);
							pause();
							break;
						case 4:
							searchSmallerDouble(list2);
							pause();
							break;
						case 5:
							list2 = removeAtStartDouble(list2);
							pause();
							break;
						case 6:
							list2 =removeAtEndDouble(list2);
							pause();
							break;
						case 7:
							printListDouble(list2);
							pause();
							break;
						case 0:
							break;
						default:
							errorMsg();
							pause();
							break;
					}
				}
				break;
			case 3:
				while(opt != 0){
					system(CLEAR);
					printf("+-------------------------------------------------------+\n");
					printf("|                      LISTA CIRCULAR                   |\n");
					switch(menu(&opt)){
						case 1:
							orderedInsertCircle(&head);
							break;
						case 2:
							head = insertToEndCircle(head);
							break;
						case 3:
							searchBiggestCircle(head);
							pause();
							break;
						case 4:
							searchSmallerCircle(head);
							pause();
							break;
						case 5:
							head = removeAtStartCircle(head);
							pause();
							break;
						case 6:
							head = removeAtEndCircle(head);
							pause();
							break;
						case 7:
							printListCircle(head);
							pause();
							break;
						case 0:
							break;
						default:
							errorMsg();
							pause();
							break;
					}
				}
				break;
			case 0:
				byeMsg();
				break;
			default:
				errorMsg();
				break;
		}
	}

	return 0;
}
