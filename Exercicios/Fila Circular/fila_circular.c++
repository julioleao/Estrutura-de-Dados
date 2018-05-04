/*
 *
 *
  Nome: Julio Cesario de Paiva Leão
  RA: 1916033
  Estrutura de Dados
  Engenharia de Software 2018/01
  
  crie uma versão dinâmica para a lista circular;
  implemente as funções de:
	enfileirar
	desenfileirar
	imprimir
	buscar por um elemento
  você pode escolher a linguagem que desenvolverá a estrutura;

 *
 *
 */
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
	// Declarando front e rear
	int rear, front;

	// Fila circular
	int size;
	int *arr;

	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};


/* Função para criar um fila circular */
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == front-1))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* inserir o primeiro elemento */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Função para deletar um elemento da fila circular
int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Função para imprimir fila circular
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nFila esta vazia\n");
		return;
	}
	printf("\nElemtentos de fila circular\n");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

// Função para imprimir fila circular
void Queue::searchQueue()
{
	if (front == -1)
	{
		printf("\nFila esta vazia\n");
		return;
	}
	printf("\nElemtentos de fila circular\n");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++){
			if(arr[i] == )
			printf("%d ",arr[i]);
		}
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

/* Driver of the program */
int main()
{
	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}
