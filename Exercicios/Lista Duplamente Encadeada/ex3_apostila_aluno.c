/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01

	3) Considerando a seguinte estrutura referente ao cadastro de alunos em uma Universidade:

	typedef struct aluno{
		int RA;
		char nome[30];
		float P1, P2, T, APS;
	}Aluno;

	Considerando uma lista duplamente encadeada, implemente as seguintes funções:

	a) Incluir um aluno no final da lista.
	b) Inserir um aluno depois do enésimo elemento da lista. A posição passada como parâmetro.
	c) Eliminar o enésimo nó da lista. A posição passada como parâmetro.
 *
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// variaveis globais;
int cont = 0;

// Estrutura de aluno
typedef struct aluno{
	int RA;
	char nome[30];
	float P1, P2, T, APS;
	struct aluno *next;
	struct aluno *prev;
}Aluno;

// Prototipação
int menu(int *opt);
Aluno* insertAtEnd(Aluno *list);
void printList(Aluno* list);
Aluno* removeElement(Aluno* list);
Aluno* insertNelement(Aluno* list);

// Inicio da função principal (main)
int main(){
	Aluno *list;
	int opt = 1;

	list = NULL; // lista inicializada

	// menu principal
	while(opt != 0){
		switch(menu(&opt)){
			case 1:
				// Inserir no fim da lista
				list = insertAtEnd(list);
				break;
			case 2:
				// Inserir aluno depois do enesimo elemento
				list = insertNelement(list);
				break;
			case 3:
				// Eliminar um aluno da lista
				list = removeElement(list);
				pause();
				break;
			case 4:
				// Imprimir lista
				printList(list);
				pause();
				break;
			case 0:
				/*Mensagem de despedida após encerrar programa*/
				free(list);
				printf("\n+-------------------------------------+\n");
				printf("|              KOWABUNGA!!!           |\n");
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

// Função para atribuir valores à struct Aluno
void insertData(Aluno *al){
	printf(">>>> Para o ALUNO %d, informe: <<<<\n\n", cont+1);
	printf("RA.................: ");
	scanf("%d", &al->RA);
	printf("NOME...............: ");
	setbuf(stdin,NULL);
	scanf("%s", al->nome);
	printf("Nota da P1.........: ");
	scanf("%f", &al->P1);
	printf("Nota da P2.........: ");
	scanf("%f", &al->P2);
	printf("Nota do TRABALHO...: ");
	scanf("%f", &al->T);
	printf("Nota da APS........: ");
	scanf("%f", &al->APS);
	cont++;
}

// Função para inserir dados no final da lista
Aluno* insertAtEnd(Aluno *list){
	Aluno* new = (Aluno*) malloc (sizeof(Aluno));
	Aluno* last = list;
	Aluno al;

	if(new == NULL){
		printf("\nERRO NA ALOCACAO DE MEMORIA\n");
		exit(1);
	}

	insertData(&al); 						// Função para inseri novos dados

											// Atribuindo os valores passado ao novo ponteiro da lista
	new->RA = al.RA;
	strcpy(new->nome, al.nome);
	new->P1 = al.P1;
	new->P2 = al.P2;
	new->T = al.T;
	new->APS = al.APS;
											

	if (last == NULL){ 						/*Verifica se a lista está vazia,
									  	      se estiver, apenas retorne a nova lista (new).*/
		return new;
	} else { 								// Se não for no inicio da lista, a inserção será no final

		if(last->next == NULL){				/*Verifica se é o primeiro elemento da lista,
									  	      se for, o proximo elemento que new aponta (new->next) recebe last->next, ou seja NULL,
									  	      o anterior ao new (new->prev) recebe a posição de last (a primeira nesse caso)
									  	      e o próximo ponteiro que last aponta (last->next) recebe a nova lista (new).*/
			new->next = last->next;
			new->prev = last;
			last->next = new;

			if(last != NULL){ 	 			/*Se last é diferente de NULL.
								   			  o ponteiro last (list-> prev), aponta para o novo nó.*/
				last->prev = new;
			}
			return list;
		} else { 							/*Caso contrário percorra até o ÚLTIMO elemento da lista, 
											  antes de NULL, e insira os dados ao próximo elemento
											  sempre ao final, realizando a mesma operação da linha 160
											  retornando, então, a lista modificada (list)*/
			while(last->next != NULL){
				last = last->next;
			}
			new->next = last->next;
			new->prev = last;
			last->next = new;

			return list;
		}

	}
}


// Funcao menu principal
int menu(int *opt){
	system(CLEAR);
	printf("+-------------------------------------------------------+\n");
	printf("| [1] - Inserir no fim da lista                         |\n");
	printf("| [2] - Inserir aluno depois do enesimo elemento        |\n");
	printf("| [3] - Eliminar um aluno da lista                      |\n");
	printf("| [4] - Imprimir a lista                                |\n");
	printf("| [0] - Sair                                            |\n");
	printf("+-------------------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}

// Função para imprimir a lista
void printList(Aluno* list){
	Aluno *al = list;
	int num = 1;

	if(list == NULL){
		printf("\tLista vazia!\n");
    	return;
  	} else {
  		printf("+---------------------------------->\n");
  		while (al != NULL){
  			printf(">>>> ALUNO %d <<<<\n\n", num);
			printf("RA.................: %d\n", al->RA);
			printf("NOME...............: %s\n", al->nome);
			printf("Nota da P1.........: %.2f\n", al->P1);
			printf("Nota da P2.........: %.2f\n", al->P2);
			printf("Nota do TRABALHO...: %.2f\n", al->T);
			printf("Nota da APS........: %.2f\n", al->APS);
  			printf("+---------------------------------->\n");
  			al = al->next;
  			num++;
  		}
  	}
}

// Função para buscar um elemento na lista
Aluno* search(Aluno* list){
	int ra;
	Aluno *aux;

	printf("Informe o RA do aluno: "); 				// Informa o valor a ser pesquisado
	scanf("%d", &ra);
	system(CLEAR);

	for(aux = list; aux != NULL; aux = aux->next){  /*realiza a busca dentro da lista, se encontrar o 
													  valor igual ao informado, retorne o elemento
													  da lista (aux).*/
		if(aux->RA == ra){
			return aux;
		}
	}
	printf("\nAluno não encontrado!!\n"); 			// Caso contrário, retorne NULL
	return NULL;
}

// Função para remover um elemento, informado pelo usuario, da lista
Aluno* removeElement(Aluno* list){
	Aluno* aux = search(list); 						// Um novo ponteiro recebe o retorno da função search()

	if(aux == NULL){  								/*Se o retorno for NULL, significa que não foi encotnrado o elemento
													  retornando assim a lista inalterada (list).*/
		return list;
	}

	if(list == aux){  								/*Se o elemento estiver na primeira posição, 
													  apenas aponte para a próxima posição*/  
		list = aux->next;
	} else { 
		aux->prev->next = aux->next; 				/*Senão, o nó a ser retirado pode ser o último da lista ou estar entre dois outros nós,
									  				 Assim, o ponteiro next do nó anterior ao nó a ser removido (aux->prev->next) 
									   				 aponta para o nó sucessor ao nó a ser retirado (aux->next).*/
	}

	if(aux->next != NULL){ 							/*Se o ponteiro next do nó apontado pelo ponteiro aux (aux->next) for diferente de
													 NULL, então, o nó a ser removido encontra-se entre dois outros nós da lista.
													 Assim, o ponteiro prev do nó sucessor ao nó a ser removido (aux->prev->next)
													 aponta para o nó anterior ao nó a ser retirado (aux->prev).*/
		aux->next->prev = aux->prev;
	}
	free(aux); 										//Desaloca o nó apontado pelo ponteiro
	printf("\n+--------------------+\n");
	printf("|   ALUNO REMOVIDO   |\n");
	printf("+--------------------+\n");
	return list; 									// Retorna a lista alterada ou inalterada
}

// Função de inserção normal
Aluno* insert(Aluno *list){
	Aluno *new = (Aluno*) malloc (sizeof(Aluno));
	Aluno al;

	if(new == NULL){
		printf("\nERRO NA ALOCACAO DE MEMORIA\n");
		exit(1);
	}

	insertData(&al); 

	new->RA = al.RA;
	strcpy(new->nome, al.nome);
	new->P1 = al.P1;
	new->P2 = al.P2;
	new->T = al.T;
	new->APS = al.APS;

	return new;
}

// Função para inserir um aluno depois do enésimo elemento da lista, informado pelo usuario.
Aluno* insertNelement(Aluno* list){
	Aluno* aux = search(list); 		// Um novo ponteiro recebe o retorno da função search()

	if(aux == NULL){  				/*Se o retorno for NULL, significa que não foi encotnrado o elemento
									  retornando assim a lista inalterada (list).*/
		return list;
	}
	Aluno* new = insert(list); 		/*Caso tenha encontrado a posição do elemento
									  um nuvo ponteiro new recebe os dados da função insert.*/

	new->next = aux->next;  		/* O proximo elemento que new aponta (new->next) recebe aux->next, ou seja, 
									   o próximo valor que o retorno da função search aponta,
									   o anterior ao new (new->prev) recebe o conteudo de aux (retorno da função search)
					  	    		   e o próximo ponteiro que aux aponta (aux->next) recebe a nova lista (new).*/
	new->prev = aux;
	aux->next = new;

	if(aux != NULL){
		aux->prev = new; 			/*Se o ponteiro aux for diferente de NULL, 
									  então o nó anterior aponta para o novo nó (new).*/
	}

	return list; 					// Retornando a lista alterada
}

