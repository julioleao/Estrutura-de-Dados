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


// Registro de contadores para lista dupla
typedef struct counter{
	int number;
	struct counter *next;
	struct counter *prev;
}Counter;

// Função que testa se a lista está vazia ou não
int testListDouble(Counter* list){
    if(list == NULL){
    	printf("Essa lista esta vazia!\n");
    	return 0;
    }
    return 1;
}

// Função inicialização de lista dupla
Counter* startDouble() {
	return NULL;
}


// Função para inserir dados de fortma ordenada na lista
Counter* orderedInsertDouble(Counter *list){
	int number;
	printf("Informe um numero: ");
	scanf("%d", &number);
	// Aloca a memoria para a lista new
	Counter *new = (Counter*) malloc (sizeof(Counter));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	new->number = number;

	// Se a lista estiver vazia, inserir o primeiro elemento
	if(list == NULL){
		new->next = NULL;
		new->prev = NULL;
		return new;
	} else { // Procura onde vai inserir o elemento
		Counter *prev;
		Counter *actual = list; // Duas listas auxiliares

		while(actual != NULL && actual->number < number){  /*Verifica toda a lista enquanto não for igual a NULL
															 ou o valor a ser insirido for menor ao da lista*/
			prev = actual;
			actual = actual->next;
		}

		if (actual == list){ // insere o elemento no inicio

			new->prev = NULL;
			list->prev = new;
			new->next = list;
			return new;
		} else { // Se não for no inicio da lista, a inserção será no meio ou no final

			new->next = prev->next;
			new->prev = prev;
			prev->next = new;

			if(actual != NULL){
				actual->prev = new;
			}

		}
		return list;
	}

}

// Função para imprimir a lista
void printListDouble(Counter* list){
    Counter* p = list;
    if(testListDouble(list) == 0){
    	return;
    } else {
		printf("+---------------------------------->\n");
	    while(p != NULL){
	        printf("Numero.....: %d\n", p->number);
	        printf("+---------------------------------->\n");
	        p = p->next;
	    }
	}
}

void searchBiggestDouble(Counter* list){
	Counter* p = list;
	int biggest = list->number;
	if(testListDouble(list) == 0){
    	return;
    } else {
		while(p != NULL){
			if(p->number > biggest){
				biggest = p->number;
			}
			p = p->next;
		}
	}
	printf("\n+--------------------------------------->\n");
	printf("O MAIOR valor encontrado e: %d\n", biggest);
  	printf("+--------------------------------------->\n");
}

// Função para encontrar o menor valor da lista
void searchSmallerDouble(Counter * list){
	Counter * p = list;
	int smaller = list->number;
	if(testListDouble(list) == 0){
    	return;
    } else {
		while(p != NULL){
			if(p->number < smaller){
				smaller = p->number;
			}
			p = p->next;
		}
	}
	printf("\n+--------------------------------------->\n");
	printf("O MENOR valor encontrado e: %d\n", smaller);
  	printf("+--------------------------------------->\n");
}

// Função para remover o primeiro valor da lista
Counter * removeAtStartDouble(Counter * list){
	Counter * begin = list->next;
	if(testListDouble(list) == 0){
    	return NULL;
    } else {
		printf("\nPrimeiro valor removido com sucesso!\n");
		return begin;
	}
}

// Função para remover o ultimo elemento da lista
Counter * removeAtEndDouble(Counter * list){
	Counter * last = list;
	if(testListDouble(list) == 0){
    	return list;
  }
	if(last->next == NULL){
		printf("\nUltimo valor removido com sucesso!\n");
		return NULL;
	}	else{
		while(last->next != NULL){
			last = last->next;
		}
		last->prev->next = NULL;
		free(last);
		printf("\nUltimo valor removido com sucesso!\n");
		return list;
	}
}

// Função para inserir um elemento no final da lista
Counter* insertToEndDouble(Counter *list){
	int number;
	Counter* last = list;
	printf("Informe um numero: ");
	scanf("%d", &number);
	// Aloca a memoria para a lista new
	Counter *new = (Counter*) malloc (sizeof(Counter));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	new->number = number;
	new->next = list;
	new->prev = NULL;

	if(testListDouble(list) == 0){
    	return list;
  }
	if(last->next == NULL){
		last->next = new;
		new->next = NULL;
		return list;
	}	else{
		while(last->next != NULL){
			last = last->next;
		}
		last->next = new;
		new->next = NULL;
		return list;
	}
}
