/**
* Professor Diogo Cezar Teixeira Batista
* <diogo@diogocezar.com>
* <diogoc@utfpr.edu.br>
* Exemplo de Fila Duplamente Encadeada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
	struct Node * prev;
} Node;

typedef struct Queue{
	Node * start;
	Node * end;
} Queue;

Queue * create(){
	Queue * q = (Queue*) malloc(sizeof(Queue));
	q->start = NULL;
	q->end = NULL;
	return q;
}

void insertEnd(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = NULL;
	if(q->end != NULL){
		q->end->next = new;
		new->prev = q->end;
	}
	else{
		q->start = new;
		new->prev = NULL;
	}
	q->end = new;
}

void insertStart(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->prev = NULL;
	if(q->end != NULL){
		q->start->prev = new;
		new->next = q->start;
	}
	else{
		q->end = new;
		new->next = NULL;
	}
	q->start = new;
}

int isEmptyQueue(Queue * q){
	return (q->start == NULL);
}

void printQueue(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return;
	}
	else{
		while(p != NULL){
			printf("Valor: %d\n", p->value);
			p = p->next;
		}
	}
}

Node * search(Queue * q, int value){
	Node * p;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return NULL;
	}
	else{
		for(p=q->start; p != NULL; p=p->next){
			if(p->value == value){
				printf("Valor %d encontrado!!!\n", value);
				return p;
			}
		}
	}
	printf("Valor nao encontrado!!!\n");
	return NULL;
}

void freeQueue(Queue * q){
	Node * p = q->start;
	while(p != NULL){
		Node * t = p->next;
		free(p);
		p = t;
	}
	free(q);
}

int removeStartQueue(Queue * q){
	Node * t;
	int v;
	t = q->start;
	v = t->value;
	q->start = t->next;
	if(t->next == NULL)
		q->end = NULL;
	else
		t->next->prev = NULL;
	free(t);
	printf("Removido com Sucesso!!\n");

	return v;
}

int removeEndQueue(Queue * q){
	Node * t;
	int v;

	t = q->end;
	v = t->value;
	q->end = t->prev;
	if(t->prev == NULL)
		q->start = NULL;
	else
		t->prev->next = NULL;
	free(t);
	printf("Removido com Sucesso!!\n");
	return v;
}

void firstPair(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return;
	}
	else{
		while(p != NULL){
			if(p->value % 2 == 0){
				printf("O primeiro numero par e: %d\n", p->value);
				return;
			}
			p = p->next;
		}
	}
	printf("Numero par nao encontrado!!!\n");
	return;
}

void lastPair(Queue * q){
	Node * p;
	p = q->end;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return;
	}
	else{
		while(p != NULL){
			if(p->value % 2 == 0){
				printf("O ultimo numero par e: %d\n", p->value);
				return;
			}
			p = p->prev;
		}
	}
	printf("Numero par nao encontrado!!!\n");
	return;
}

void orderedDecres(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return;
	}
	else{
		while(p->next != NULL){
			if(p->value < p->next->value){
				printf("A fila NAO esta em ordem decrescente!!!\n");
				return;
			}
			p = p->next;
		}
	}
	printf("A fila esta em ordem decrescente!!!\n");
	return;
}

void printQueue2(Queue * q, Queue * q2){
	Node * p, *p2;
	p = q->start;
	p2 = q2->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
		return;
	}
	else{
		printf("FILA 1     |FILA 2\n");
		while(p2 != NULL){
			printf("%d          |%d\n", p->value, p2->value);
			p = p->next;
			p2 = p2->next;
		}
	}
}

void compareQueue(Queue* q, Queue* q2){
	Node *p, *p2;
	p = q->start;
	p2 = q2->start;

	while(p != NULL){
		if (p->value != p2->value){
			printf("Filas diferentes!!!\n\n");
			printQueue2(q, q2);
			return;
		} else {
			p = p->next;
			p2 = p2->next;
		}
	}
	
	printf("As duas filas sao iguais!!!\n\n");
	printQueue2(q, q2);
	return;
}