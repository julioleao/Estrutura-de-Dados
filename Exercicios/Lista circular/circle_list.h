/*
 *
 *
	Nome: Julio Cesario de Paiva Leão
	RA: 1916033
	Estrutura de Dados
	Engenharia de Software 2018/01
	TAD - Lista Circular
 *
 *
 */


// Registro de contadores para lista circular
typedef struct circle{
	int number;
	struct circle *next;
}Circle;

// Função para imprimir a lista preenchida
void printListCircle(Circle *head){
	if(head == NULL){
		printf("Lista vazia!\n");
	} else {
		Circle *print = head;
		printf("+---------------------------------->\n");
		while(print->next != head){
			printf("Numero: %d\n", print->number);
			printf("+---------------------------------->\n");
			print = print->next;
		}
		printf("Numero: %d\n", print->number);
		printf("+---------------------------------->\n");
	}
}

// Função para alocar memória para lista simples
Circle* malocCircle(Circle *head){
	// Aloca a memoria para a lista new
	Circle *new = (Circle*) malloc (sizeof(Circle));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	return new;
}

// Função para inserir dados de forma ordenada na lista
void orderedInsertCircle(Circle **head) {
	int number;
	Circle* current = *head;

	printf("Informe um numero: ");
	scanf("%d", &number);
	Circle *new = (Circle*) malloc (sizeof(Circle));

	new->number = number;
	  // Case 1 of the above algo
  	if (current == NULL){
     	new->next = new;
     	*head = new;
  	}
 
  	// Case 2 of the above algo
  	else if (current->number >= new->number){
    /* If value is smaller than head's value then
      we need to change next of last node */
    	while(current->next != *head){
        	current = current->next;
    	}
    	current->next = new;
	    new->next = *head;
	    *head = new;
  	}
 
  	// Case 3 of the above algo
  	else{
    /* Locate the node before the point of insertion */
    	while (current->next!= *head && current->next->number < new->number){
      		current = current->next;
    	}
 
    	new->next = current->next;
    	current->next = new;
  }

}

// Função para encontrar o maior valor da lista
void searchBiggestCircle(Circle* head){
	
	if(head == NULL){
		printf("Lista vazia!\n");
    	return;
    } else {
    	int biggest = head->number;
    	Circle * p = head;
		while(p->next != head){
			if(p->number > biggest){
				biggest = p->number;
			}
			p = p->next;
		}
		if(p->number > biggest){
				biggest = p->number;
		}
		printf("\n+--------------------------------------->\n");
		printf("O MAIOR valor encontrado e: %d\n", biggest);
  		printf("+--------------------------------------->\n");
	}
	
}

// Função para encontrar o menor valor da lista
void searchSmallerCircle(Circle * head){

	if(head == NULL){
		printf("Lista vazia!\n");
    	return;
    } else {
    	int smaller = head->number;
    	Circle * p = head;
		while(p->next != head){
			if(p->number < smaller){
				smaller = p->number;
			}
			p = p->next;
		}
		if(p->number < smaller){
				smaller = p->number;
		}
		printf("\n+--------------------------------------->\n");
		printf("O MENOR valor encontrado e: %d\n", smaller);
  		printf("+--------------------------------------->\n");
	}
	
}

// Função para remover o primeiro valor da lista
Circle* removeAtEndCircle(Circle * head){
	if(head == NULL){
		printf("Lista vazia!\n");
    	return NULL;
    } else {
    	Circle * last = head->next;
    	Circle * penultimate = head->next;
    	if(last->next == head){
    		printf("\nUltimo valor removido com sucesso!\n");
    		free(last);
    		return NULL;
    	} else {
    		head = head->next;
    		last = head;
    		printf("\nUltimo valor removido com sucesso!\n");
    	}
		
	}
	return head;
}

// Função para remover o primeiro elemento da lista
Circle * removeAtStartCircle(Circle * head){
	if(head == NULL){
		printf("Lista vazia!\n");
		return NULL;
	}
	Circle * last = head;
	Circle * nextNode = head->next;
	if(last->next == head){
		return NULL;
	}else{
		
		while(last->next != head){
			last = last->next;
		}

		if (last == NULL){
			return head;
		}

		last->next = nextNode;
		free(head);
		printf("\nPrimeiro valor removido com sucesso!\n");
	}
	return nextNode;
}

// Função para inserir um elemento no final da lista
Circle* insertToEndCircle(Circle *head){
	int number;

	printf("Informe um numero: ");
	scanf("%d", &number);

	// Aloca a memoria para a lista new
	Circle *new = (Circle*) malloc (sizeof(Circle));
	// Testa se foi alocada a memoria
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	new->number = number;

	if (head == NULL) {
		head = new;
		new->next = head;
		return new;
	} else {
		Circle *last = head;
		while(last->next != head){
			last = last->next;
		}

		last->next = new;
		new->next = head;
		return head;
	}
}
