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

// Funcao principal
int main(){
	// Variavel para controlar laco do menu
	int opt = 1;
	Counter *list;

	// Iniciar a lista de contadores
	list = start();

	// menu principal
	while(opt != 0){
		switch(menu(&opt)){
			case 1:
				// Inserir de forma ordenada
				list = orderedInsert(list);
				//pause();
				break;
			case 2:
				// Inserir no fim de uma lista
				list =  insertToEnd(list);
				pause();
				break;
			case 3:
				// Encontrar o maior elemento
				searchBiggest(list);
				pause();
				break;
			case 4:
				// Encontrar o menor elemento
				searchSmaller(list);
				pause();
				break;
			case 5:
				// Remover do inicio
				list = removeAtStart(list);
				pause();
				break;
			case 6:
				// Remover do fim
				list = removeAtEnd(list);
				pause();
				break;
			case 7:
				// Imprimir a lista
				printList(list);
				pause();
				break;
			case 0:
				/*Mensagem de despedida após encerrar programa*/
				free(list);
				printf("\n+-------------------------------------+\n");
				printf("|   VALEU, FALOU E ATE....ATE MAIS.   |\n");
				printf("+-------------------------------------+\n\n");
				break;
			default:
				/*Mensagem de erro após digitar algum comando inválido*/
				printf("\n+--------------------+\n");
				printf("|   OPCAO INVALIDA   |\n");
				printf("+--------------------+\n");
				pause();
				break;
		}
	}

	return 0;
}
