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
typedef struct unique{
	int number;
	struct unique *next;
}Unique;

// Função que testa se a lista está vazia ou não
int testListUnique(Unique* list){
    if(list == NULL){
    	printf("Essa lista esta vazia!\n");
    	return 0;
    }
    return 1;
}

// Função inicialização de lista simples
Unique* startUnique(){
	return NULL;
}

// Função para alocar memória para lista simples
Unique* malocUnique(Unique *list){
	// Aloca a memoria para a lista new
	Unique *new = (Unique*) malloc (sizeof(Unique));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	return new;
}

// Função para inserir dados de fortma ordenada na lista
Unique* orderedInsertUnique(Unique *list){
	int number;
	printf("Informe um numero: ");
	scanf("%d", &number);
	Unique *new = malocUnique(list);
	new->number = number;

	// Se a lista estiver vazia, inserir o primeiro elemento
	if(list == NULL){
		new->next = NULL;
		return new;
	} else { // Procura onde vai inserir o elemento
		Unique *prev = NULL, *actual = list; // Tres listas auxiliares

		while(actual != NULL && actual->number < number){  /*Verifica toda a lista enquanto não for igual a NULL
														 														 ou o valor a ser insirido for menor ao da lista*/
			prev = actual;
			actual = actual->next;
		}

		if (actual == list){ // insere o elemento no inicio
			new->next = list;
			return new;
		} else { // Se não for no inicio da lista, a inserção será no meio ou no final

			new->next = actual;
			prev->next = new;

		}
		return list;
	}

}

// Função para imprimir a lista
void printListUnique(Unique* list){
    Unique* p = list;
    if(testListUnique(list) == 0){
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

void searchBiggestUnique(Unique* list){
	Unique* p = list;
	int biggest = list->number;
	if(testListUnique(list) == 0){
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
void searchSmallerUnique(Unique * list){
	Unique * p = list;
	int smaller = list->number;
	if(testListUnique(list) == 0){
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
Unique * removeAtStartUnique(Unique * list){
	Unique * begin = list->next;
	if(testListUnique(list) == 0){
    	return NULL;
    } else {
		printf("\nPrimeiro valor removido com sucesso!\n");
		return begin;
	}
}

// Função para remover o ultimo elemento da lista
Unique * removeAtEndUnique(Unique * list){
	Unique * last = list;
	Unique * penultimate = NULL;
	if(testListUnique(list) == 0){
    	return list;
 	}
	if(last->next == NULL){
		printf("\nUltimo valor removido com sucesso!\n");
		return NULL;
	}else{
		while(last->next != NULL){
			penultimate = last;
			last = last->next;
		}

		if (last == NULL){
			return list;
		}

		if(penultimate == NULL){
			list = last->next;
		} else {
			penultimate->next = last->next;
		}
		free(last);
		printf("\nUltimo valor removido com sucesso!\n");
		return list;
	}
}

// Função para inserir um elemento no final da lista
Unique* insertToEndUnique(Unique *list){
	int number;
	Unique* last = list;
	printf("Informe um numero: ");
	scanf("%d", &number);
	// Aloca a memoria para a lista new
	Unique *new = (Unique*) malloc (sizeof(Unique));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	new->number = number;
	new->next = NULL;

	if (list == NULL) {
		new->next = list;
		return new;
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
