/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	
	4) Implemente uma função que realize a ordenação de uma lista duplamente encadeada.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>


// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// funcao para pausar a tela com msg de retorno
void pause(){
	printf("\nPressione ENTER para voltar... ");
	setbuf(stdin,NULL);
	getchar();
}

// Registro de contadores
typedef struct counter{
	int number;
	struct counter *next;
	struct counter *prev;
}Counter;

int totNodes = 0;

// Prototipacao
Counter* insert(Counter* list);
void print(Counter* list);
int menu(int *op);
void ordenationList(Counter *list);


// Inicio da função principal (main)
int main(){
	Counter* list = NULL;
	int op = 1;

	while(op != 0){
		switch(menu(&op)){
			case 1:
				list = insert(list);
				totNodes++;
				break;
			case 2:
				print(list);
				pause();
				break;
			case 3:
				ordenationList(list) ;
				
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
// Fim da função principal

Counter* insert(Counter* list){
	Counter* new = (Counter*) malloc (sizeof(Counter));

	int num;

	printf("\nInforme um numero: ");
	scanf("%d", &num);

	new->number = num;
	new->next = list;
	new->prev = NULL;

	if (list != NULL){
		list->prev = new;
	}
	return new;
}

void print(Counter* list){
	Counter* aux = list;

	if (aux == NULL){
		printf("Lista vazia!\n");
		return;
	} else {
		while(aux != NULL){
			printf("%d\n", aux->number);
			aux = aux->next;
		}
	}
}

int menu(int *op){
	system(CLEAR);
	printf("+------------------------------------+\n");
	printf("| [1] - Inserir                      |\n");
	printf("| [2] - Imprimir                     |\n");
	printf("| [3] - Ordenar                      |\n");
	printf("| [0] - Sair                         |\n");
	printf("+------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", op);
	system(CLEAR);
	return *op;
}

 
// Função para combinar duas listas Function to merge two linked lists
Counter* merge(Counter* first, Counter* second)
{
    // Se a primeira lista estiver vazia, retorne a segunda
    if (!first)
        return second;
 
    // ISe a segunda lista estiver vazia, retorne a primeira
    if (!second)
        return first;
 
    // Encontar o menor valor
    if (first->number < second->number){
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Função para dividir a lista duplamente encadeada em duas metades
Counter* split(Counter* head){
    Counter* fast = head, *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Counter* temp = slow->next;
    slow->next = NULL;
    return temp;
}

 
// Função para o merge sort
Counter* mergeSort(Counter* head)
{
    if (!head || !head->next)
        return head;
    Counter* second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}

// Função para ordenar a lista de forma Crescente
void ordenationList(Counter *list) {
    Counter *ptr1, *ptr2; 
    int i, j, aux;
    ptr1 = ptr2 = list;                    								// Dois ponteiros que receberão o primeiro valor de list

    if (list == NULL){
		printf("Lista vazia!\n"); 										// teste para verificar se a lista esta vazia
		return;
	} else {
		for (i = 0; i < totNodes; i++) {   								/* no primeiro laço totNodes é uma variável global 
								    							          que realiza a contagem de cada nó inserido
								    									  usado como indice de parada.*/

	            aux = ptr1->number;        								// aux recebe o valor de ptr1

	            for (j = 0; j < i; j++)    								// entra no segundo laço

	                    ptr2 = ptr2->next; 								//ptr2 aponta para o próximo valor

	            for (j = i; j > 0 && ptr2->prev->number > aux; j--) { 	/*terceiro laço irá se repetir enquanto j for menor que 0
	            													      ou o ptr2->prev->number (o valor ponteiro anterior) 
	            													      for menor que aux*/

	                    ptr2->number = ptr2->prev->number;  		 	/*o valor de ptr2 passa a ser o 
	                    									  			  valor do ponteiro anterior de ptr2*/

	                    ptr2 = ptr2->prev; 								// ptr2 recebe o posição do ponteiro (ptr2) anterior
	            }
	            ptr2->number = aux;    									/*fora do laço ptr2 receber o valor de aux,
	            					     								no qual armazena o valor de ptr1 */

	            ptr2 = list; 											// ptr2 recebe list novamente

	            ptr1 = ptr1->next;  									/*incrementa ptr1 para a proxima posição da lista
	            					  									  e assim recomeçar o laço novamente*/
	    }
	}
	printf("\n+--------------------+\n");
	printf("|   LISTA ORDENADA   |\n"); 								// Fim da ordenação
	printf("+--------------------+\n");
}