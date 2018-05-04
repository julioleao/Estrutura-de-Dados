/*
 *
 *
  Nome: Julio Cesario de Paiva Leão
  RA: 1916033
  Estrutura de Dados
  Engenharia de Software 2018/01
  
    > implemente uma função que verifica se os elementos de uma fila representada
    por uma lista duplamente encadeada estão ordenados de forma decrescente;

    > faça uma função que encontre o primeiro número par mais próximo do início;

    > faça uma função que encontre o primeiro número par mais próximo do fim;

    > faça uma função recursiva que compare se duas filas duplamente encadeadas são iguais;
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "default.h"
#include "fila_dupla.h"

int limit = 0;

int main(){
  Queue * q;
  Queue * q2;
  q2 = create();
  q = create();
  insertStart(q2, 1);
  insertStart(q2, 2);
  insertStart(q2, 3);
  insertStart(q2, 4);
  insertStart(q2, 5);
  insertStart(q2, 6);
  insertStart(q2, 7);
  int limit2 = 7;

 
  int opt = 1, num;

  while(opt != 0){
  	switch(menuQueueDouble(&opt)){
  		case 1:
        printf("Informe um valor: ");
        scanf("%d", &num);
        insertStart(q, num);
        limit++;
  			break;
  		case 2:
        printf("Informe um valor: ");
        scanf("%d", &num);
        insertEnd(q, num);
        limit++;
  			break;
  		case 3:
        printQueue(q);
        /*printQueue2(q, q2);*/
  			pause();
  			break;
  		case 4:
  	    printf("Informe um valor: ");
        scanf("%d", &num);
        system(CLEAR);
        search(q, num);
  			pause();
  			break;
  		case 5:
        if(isEmptyQueue(q)){
          printf("\nFila já vazia!\n");
          
        }else{
          removeStartQueue(q);
          limit--;
        }
        pause();
  			break;
      case 6:
        if(isEmptyQueue(q)){
          printf("\nFila já vazia!\n");
          
        }else{
          removeEndQueue(q);
          limit--;
        }
        pause();
        break;
      case 7:
        orderedDecres(q);
        pause();
        break;
      case 8:
        firstPair(q);
        pause();
        break;
      case 9:
        lastPair(q);
        pause();
        break;
      case 10:
        if(limit != limit2){
          printf("Filas com tamanhos diferente!!!\n");
        }else{
          compareQueue(q, q2);
        }
        pause();
        break;
  		case 0:
  			//freeQueue(q);
  			byeMsg();
  			break;
  		default:
  			errorMsg();
  			pause();
  			break;
  	}
  }
  return 0;
}