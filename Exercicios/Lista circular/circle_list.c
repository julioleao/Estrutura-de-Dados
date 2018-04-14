/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	as estruturas: lista encadeada e lista duplamente encadeada são semelhantes;
	implemente as mesmas operações adicionais que foram explicadas na aula passada:
	encontrar o maior elemento;
	encontrar o menor elemento;
	inserir de forma ordenada;
	inserir no fim de uma lista;
	remover do início de uma lista;
	remover do fim de uma lista;
	escreva alguns parágrafos dizendo: o fato da lista ser duplamente encadeada
	pode melhorar o custo de alguma das operações? por que?
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list.h"
#include "default.h"
#include "unique_list.h"

// Prototipação
int menu(int *opt);

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
							pause();
							break;
					}
				}
				break;
			case 2:

				while(opt != 0){
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
					switch(menu(&opt)){
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						case 7:
							break;
						case 0:
							break;
						default:
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
