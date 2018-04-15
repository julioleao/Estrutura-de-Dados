/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	> implemente para a lista circular a função para a remoção de um elemento
	que deverá ser passado como parâmetro;
	> implemente uma função para a lista circular que retorne a média
	de todos os elementos da lista;
	> escreva alguns parágrafos dizendo: explicando em que situações uma lista 
	circular seria bem empregada, por qual motivo?

 *
 *
 */




#include <stdio.h>
#include <stdlib.h>
#include "default.h"


typedef struct grade{
	float number;
	struct grade *next;
}Grade;

// Variáveis globais
int cont = 0;
Grade *head = NULL;

// Prototipação
void insertCircle();
void printList();
void mean();
void deleteSpecific();

// Inicio da função principal (main)
int main(){
	
	int opt = 1;

	while(opt != 0){
		switch(menu3(&opt)){
			case 1:
				insertCircle();
				break;
			case 2:
				printList();
				pause();
				break;
			case 3:
				deleteSpecific();
				pause();
				break;
			case 4:
				mean();
				pause();
				break;
			case 0:
				free(head);
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
// Fim da função principal


// Função para testar se a lista é vazia ou não
int testListCircle(){
	if (head == NULL){
		return 0;
	}
	return 1;
}

// Função para inserir um elemento na lista circular
void insertCircle(){
	float num;
	Grade *new = (Grade*) malloc (sizeof(Grade));

	printf("Informe um numero: ");
	scanf("%f", &num);

	new->number = num;

	if(head == NULL){
		head = new;
		new->next = head;
	} else {
		Grade *temp = head;
     	while(temp->next != head){
        	temp = temp -> next;
     	}
    	temp->next = new;
    	new->next = head;
	}
	cont ++;
}

// Função para imprimir a lista preenchida
void printList(){
	if(head == NULL){
		printf("Lista vazia!\n");
	} else {
		Grade *print = head;
		while(print->next != head){
			printf("Valor: %3.2f\n", print->number);
			print = print->next;
		}
		printf("Valor: %3.2f\n", print->number);
	}
}

// Função para imprimir a média de todos os valores
void mean(){
	float sum = 0;
	if(head == NULL){
		printf("Lista vazia!\n");
	} else {
		Grade *aux = head;
		while(aux->next != head){
			sum = sum + aux->number;
			aux = aux->next;
		}
		sum = sum + aux->number;
		sum = sum/cont;
		printf("Media total e: %3.2f\n", sum);
	}
}

// Função para remover qualquer valor que o usuário digitar
void deleteSpecific(){

    if(head == NULL){                     									// Checar se a lista está vazia (head == NULL)
    	printf("Lista vazia!\n");
    } else {
    	float num;
	    Grade *temp1 = head, *temp2;    									/* Se não está vazia, define dois ponteiros temporarios *temp1 e *temp2
	    								  									   sendo que temp1 recebe head.*/

		printf("Informe o valor que deseja excluir: "); 					// Informar o valor a ser deletado
		scanf("%f", &num);
		system(CLEAR);
		if(temp1->next == head && temp1->number == num){ 					// Se o valor que deseja remover e for a unica posição
	       head = NULL; 													// head recebe NULL, e libere temp1 (free(temp1)).
	       free(temp1);														// Libera temp1
	       printf("\nElemento deletado com sucesso!!!\n"); 					// Finaliza a função com uma msg de remoção
	       cont--;															// Decrementa cont para não prejudicar a média
	       return;
	    } 

	    while(temp1->number != num){  										// repetir enquanto o valor da lista for diferente do informado
	        if(temp1->next == head){  										// Se chegar ao ultimo nó e não encontrar o valor imprima a msg
	            printf("\nO valor informado não se encontra na lista!!!\n");  
	            return; 													// Retorne head sem alteração
	        } else {
	            temp2 = temp1;  											/* Caso não tenha chego no valor desejado nem ao final da lista,
	            				  											   o ponteiro temporario temp2 recebe temp1 e temp1 recebe seu proximo elemento, temp1->next.*/
	            temp1 = temp1->next;
	        }
	    }
        if(temp1 == head){ 													// Caso seja o primeiro nó da lista
            temp2 = head;  													// Então temp2 recebe head
            while(temp2->next != head){ 									// Vai repetindo até temp2 chegar ao nultimo nó
            	temp2 = temp2->next;
            }
            head = head->next; 												// Chegando ao último nó, head recebe seu próximo valor
            temp2 -> next = head;											// temp2 (ultimo nó) recebe head, deixando assim de existir o primeiro elemento 
            free(temp1); 													// Libera temp1
        } else {
            if(temp1->next == head) 										// Se temp1 não é o primeiro nó, então verifica-se se é o ultimo
            {
               temp2->next = head; 											// Se temp1 for o ultimo, temp2->next recebe head (a primeira posição sobrescreve a ultima)
            }
            else 															/* Se temp1 não for o ultimo, então está no meio,
            																   nesse caso, temp2->next recebe a próxima posição que temp1 aponta
            																   (temp1->next).*/
            {
               temp2->next = temp1->next;
            }   
            free(temp1); // Libera temp1

        }

	    printf("\nElemento deletado com sucesso!!!\n"); 					// Finaliza a função com uma msg de remoção
	    cont--;	    														// Decrementa cont para não prejudicar a média
	}
}