// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Registro de inscritos
typedef struct subscribers{
	char name[50];
	int age;
	struct subscribers *next;
}Subs;

// Registro de canal
typedef struct youtube{
	char channel_name[50];
	Subs *s;
	int total_view;
	int qtd_videos;
	struct youtube *next;
}Tube;

// Prototipação
Subs* insertSub(Subs *listSub, char sub_name[50], int age);
int testList(Tube *list);


// funcao para pausar a tela com msg de retorno
void pause(){
	printf("\nPressione ENTER para voltar... ");
	setbuf(stdin,NULL);
	getchar();
}

// Funcao menu principal
int menu(int *opt){
	system(CLEAR);
	printf("+--------------------------------------------------------------+\n");
	printf("| [1] - Adicionar canal                                        |\n");
	printf("| [2] - Listar todos os canais                                 |\n");
	printf("| [3] - Mostrar canal com a maior quantidade de visualizacoes  |\n");
	printf("| [4] - Mostrar canal com a menor quantidade de visualizacoes  |\n");
	printf("| [5] - Remover o ultimo canal da lista                        |\n");
	printf("| [6] - Remover o primeiro canal da lista                      |\n");
	printf("| [7] - Mostrar a quantidade de inscritos de cada canal        |\n");
	printf("| [0] - Sair                                                   |\n");
	printf("+--------------------------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}

// Função inicialização lista canal
Tube* start() {
	return NULL;
}

// Função inicialização lista inscritos
Subs* startSubs() {
	return NULL;
}

// Função para inserir dados do canal
Tube* insert(Tube *list, Subs *listSub, char name[], int views, int videos){
	char op = 'S';
	char sub_name[50];
	int age, cont = 1;
	Tube *novo = (Tube*) malloc (sizeof(Tube));
	if(novo == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	strcpy(novo->channel_name,name);
	novo->total_view = views;
	novo->qtd_videos = videos;
	// inicializando a lista de inscritos
	novo->s = startSubs();
	while(op != 'N' && op != 'n'){
		printf("\nInforme o nome do inscrito %d............: ", cont);
		scanf("%s", sub_name);
		printf("Informe a idade do inscrito %d...........: ", cont);
		scanf("%d", &age);
		// preenchendo a lista de inscritos
		novo->s = insertSub(novo->s, sub_name, age);
		printf("\nDeseja cadastrar mais inscritos?? <S> <N> : ");
		setbuf(stdin,NULL);
		scanf("%c", &op);
		cont ++;
	}
	novo->next = list;
	return novo;
}

// Função para inserção de dados na lista inscritos
Subs* insertSub(Subs *listSub, char sub_name[50], int age){
	Subs *new = (Subs*) malloc (sizeof(Subs));
	if(new == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
	strcpy(new->name,sub_name);
	new->age = age;
	new->next = listSub;
	return new;
}

// Função para imprimir a lista
Tube* printList(Tube* list){
    Tube* p = list;
    if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else {
		printf("+---------------------------------->\n");
	    while(p != NULL){
	        printf("Nome do canal.....: %s", p->channel_name);
	        printf("\nQtd de views......: %d", p->total_view);
	        printf("\nQtd de videos.....: %d\n", p->qtd_videos);
	        printf("+---------------------------------->\n");
	        p = p->next;
	    }
	}
}

// Função para encontrar o canal com mais views
Tube* searchBiggest(Tube* list){
	
	Tube* p = list;
	Tube* aux = list;
	int biggest = list->total_view;
	if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else {
    	
		while(p != NULL){
			if(p->total_view > biggest){
				biggest = p->total_view;
				aux = p;
			}
			p = p->next;
		}
	}
	printf("O canal com o MAIOR numero de views e:\n");
	printf("\n+---------------------------------->\n");
	printf("Nome do canal.....: %s", aux->channel_name);
    printf("\nQtd de views......: %d", aux->total_view);
    printf("\nQtd de videos.....: %d\n", aux->qtd_videos);
    printf("+---------------------------------->\n");
}

// Função para encontrar o canal com menos views
Tube* searchSmaller(Tube * list){
	Tube * p = list, *aux = list;
	int smaller = list->total_view;
	if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else {
		while(p != NULL){
			if(p->total_view < smaller){
				smaller = p->total_view;
				aux = p;
			}
			p = p->next;
		}
	}
	printf("O canal com o MENOR numero de views e:\n");
	printf("\n+---------------------------------->\n");
	printf("Nome do canal.....: %s", aux->channel_name);
    printf("\nQtd de views......: %d", aux->total_view);
    printf("\nQtd de videos.....: %d\n", aux->qtd_videos);
    printf("+---------------------------------->\n");
}

// Função para remover o primeiro canal da lista
Tube * removeAtStart(Tube * list){
	Tube *p = list;
	if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else{
		Tube * aux = list->next;
		list->next = aux->next;
		printf("\nPrimeiro canal removido com sucesso!\n");
		return aux;
	}
}

// Função para remover o ultimo canal da lista
Tube * removeAtEnd(Tube * list){
	Tube *p = list;
	if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else{
		Tube * last = list->next;
		Tube * penultimate = list;
		while(last->next != NULL){
			penultimate = last;
			last = last->next;
		}
		penultimate->next = NULL;
		printf("\nUltimo canal removido com sucesso!\n");
		return last;
	}
}

// Função para contar inscritos
int cont(Subs *sub){
	int i;
	Subs *s = sub;
	
	for(i = 0; s != NULL; i++){
		s = s->next;
	}
	return i;
}

// Função para percorrer a lista de canais e mostrar 
// a quantidade de inscritos
Tube* contSubs(Tube *list){
	Tube *p = list;
	int counter;
	if(p == NULL){
    	printf("Essa lista esta vazia!\n");
    	return NULL;
    } else {
		while(p != NULL){
			// counter recebe a quantidade de inscritos de um canal
			counter = cont(p->s);
			printf("Canal %s possui %d inscritos.\n", p->channel_name, counter);
			p = p->next;
		}
	}
}


