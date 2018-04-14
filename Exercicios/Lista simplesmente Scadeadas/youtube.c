/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	SO33A-ES31] T07 - Operações com Listas Encadeadas
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_channel.h"


int main(){
	int opt = 1, views, videos;
	Tube *list;
	Subs *listSub;
	char name[50];
	list = start();
	// menu principal
	while(opt != 0){
		switch(menu(&opt)){
			case 1:
				// Inserir canais e inscritos
				printf("Informe o nome do canal.................: ");
				scanf("%s", name);
				printf("Informe a qtd de views..................: ");
				scanf("%d", &views);
				printf("Informe a qtd de videos.................: ");
				scanf("%d", &videos);
				list = insert(list, listSub, name, views, videos);
				pause();
				break;
			case 2:
				// Imprimir lista de canais
				printList(list);
				pause();
				break;
			case 3:
				// Busca pelo canal com mais views
				searchBiggest(list);
				pause();
				break;
			case 4:
				// Busca pelo canal com menos views
				searchSmaller(list);
				pause();
				break;
			case 5:
				// Remover o ultimo canal da lista
				list = removeAtEnd(list);
				pause();
				break;
			case 6:
				// Remover o primeiro canal da lista
				list = removeAtStart(list);
				pause();
				break;
			case 7:
				//Contagem de inscritos de cada canal
				contSubs(list);
				pause();
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
				pause();
				break;
		}
	}

	return 0;
}
