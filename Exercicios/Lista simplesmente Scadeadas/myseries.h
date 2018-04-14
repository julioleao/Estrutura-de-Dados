// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Registro de series
typedef struct Series{
	char name[50];
	int min;
	struct Series *nextEpi;
}Series;


// Função para iniciar uma lista em NULL
Series* start(){
	return NULL;
}

// Função para inserir conteúdo na lista
Series* insert(Series* list, char name[], int min){
    Series *novo = (Series*) malloc (sizeof(Series));
    if(novo == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
    strcpy(novo->name, name);
    novo->min = min;
    novo->nextEpi  = list;
    return novo;
}

// Função para imprimir a lista
void printList(Series* list){
    Series* p = list;
    if(p == NULL){
        printf("Essa lista está vazia!\n");
    }
    else{
    	printf("+---------------------------------->\n");
        while(p != NULL){
            printf("Nome.....: %s", p->name);
            printf("\nDuracao..: %d min\n", p->min);
            printf("+---------------------------------->\n");
            p = p->nextEpi;
        }
    }
}

// Função para buscar pelo Nome
Series * searchName(Series * list, char *name){
    Series * p;
    for(p=list; p!=NULL; p=p->nextEpi){
        if(strcmp(p->name,name) == 0){
            return p;
        }
    }
    return NULL;
}

// Função para buscar pela duração (min) 
Series * searchMin(Series * list, int min){
    Series * p;
    for(p=list; p!=NULL; p=p->nextEpi){
        if(p->min == min){
            return p;
        }
    }
    return NULL;
}

// Função para liberar a lista (remover todos os elementos)
void freeList(Series * list){
    Series * p = list;
    while(p != NULL){
        printf("Elemento removido: %s - %d min\n", p->name, p->min);
        Series * temp = p->nextEpi;
        free(p);
        p = temp;
    }
    p = NULL;
}

// Função que remove um item da lista através do nome
Series * removeList(Series * list, char *name){
    Series * p = list;
    Series * prior = NULL;
    // verifica se for o primeiro
    if(strcmp(name,list->name) == 0){
	    prior = list;
	    list = list->nextEpi;
	    free(prior);
	    printf("\nSerie removida com sucesso!\n");
	    return list;
	}
    while((p != NULL) && (strcmp(p->name,name) != 0)){
        prior = p;
        p = p->nextEpi;
    }
    if(p == NULL){
    	printf("\nSerie não encontrada!\n");
        return list;
    }
    else{
        prior->nextEpi = p->nextEpi;
        printf("\nSerie removida com sucesso!\n");
    }
    free(p);
    return list;
}

// Imprimi a lista na tela de forma recursiva
void printRecursive(Series * list){
    Series * p = list;
   
    if(p != NULL){
    	printf("Nome.....: %s", p->name);
        printf("\nDuracao..: %d min\n", p->min);
        printf("+---------------------------------->\n");

        printRecursive(p->nextEpi);
    }
}

// Imprimi a lista na tela de forma recursiva invertida
void printInvertedRecursive(Series * list){
    Series * p = list;
    if(p != NULL){
		printRecursive(p->nextEpi);

    	printf("Nome.....: %s", p->name);
        printf("\nDuracao..: %d min\n", p->min);
        printf("+---------------------------------->\n");
	}
}
