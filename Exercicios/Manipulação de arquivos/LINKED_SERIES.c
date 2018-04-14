/**
  * Julio Cesario de Paiva Leão
  * RA 1916033
  * Turma: ES21
  * Prof. Diogo​​ Cezar​​ Teixeira​​ Batista

  * Trabalho FINAL

  * Esse é um programa serve para gerenciar todas séries / filmes assistidos
    inserindo seus nomes e datas. Salvando e recupeando de arquivos em TXT.
    Realizando buscas e exclusões. Tudo através de listas encadeadas.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Hack para destroy a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Registro item com data e nome
typedef struct Item{
    char date[11];
    char name[100];
    struct Item* next;
}Item;

// Variaveis globais
int option;
char arq[20];
int cont = 0;
long tam = 0;

// Prototipação de funções
Item* start();
Item* insert(Item *list, char *date, char *name);
void print(Item * list);
void inserirItem(Item *list, char *date, char *name);
void printRecursive(Item* list);
void printRecursiveInverted(Item* list);
int save(Item *list);
Item* load(Item *list);
void destroy(Item *list);
void search(Item * list);

// Função principal
int main(){
    Item *list;
    char date[11], name[100], op;
    list = start();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    do{
        switch(menu()){
            case 1:
                inserirItem(list, date, name); // Inserir um item
                list = insert(list, date, name); // Ponteiro list recebe o retorno da função insert, o qual retorna um novo ponteiro para a próxima posição
                break;
            case 2:
                if(list != NULL){
                    printf("\n\aHA REGISTRO NA MEMORIA E SERAO APAGADOS, DESEJA CONTINUAR S / N: ");
                    scanf(" %c", &op);
                    if (op == 'N' || op == 'n'){
                        break;
                    } else {
                        system(CLEAR);
                        list = load(list); // Abrir arquivo de TXT e enviar para a memória
                    }
                } else {
                    list = load(list); // Abrir arquivo de TXT e enviar para a memória
                }
                break;
            case 3:
                print(list); // Listar de forma iterativa
                break;
            case 4:
                printRecursive(list); // Listar de forma Recursiva
                getch();
                break;
            case 5:
                printRecursiveInverted(list); // Listar de forma recursiva invertida
                getch();
                break;
            case 6:
                destroy(list); // Limpar lista da memória
                list = start(); // Apontar NULL para o inicio da lista
                break;
            case 7:
                save(list); // Salvar arquivo TXT
                break;
            case 8:
                printf("\n\t\aHA UM TOTAL DE %d ITEM(S) E %d BYTES DE MEMORIA!\n", cont, tam); // Mensagem informando quantidade de registros e tamanho do aquivo em bytes
                getch();
                break;
            case 9:
                search(list); // Buscar registro por data
                break;
            case 10:
                printf("\n\t\aATE MAIS JOVEM PADAWAN!\n"); // Mensagem de saída
                break;
        }
    } while (option != 10);

    return 0;
}

// Função Menu
int menu(){

    do{
        system(CLEAR);
        printf("\t+-------------------------------------------------------------+\n");
        printf("\t|\t\t\t\t\t\t\t      |\n");
        printf("\t| Ola, vem-vindo ao sistema de gerencia de series e filmes!   |\n");
        printf("\t|\t\tO que voce deseja fazer?\t\t      |\n");
        printf("\t|\t\t\t\t\t\t\t      |\n");
        printf("\t| [ 01 ] - Inserir um item manualmente\t\t\t      |\n");
        printf("\t| [ 02 ] - Carregar um arquivo com os meus itens\t      |\n");
        printf("\t| [ 03 ] - Listar os itens de forma iterativa\t\t      |\n");
        printf("\t| [ 04 ] - Listar as itens de forma recursiva\t\t      |\n");
        printf("\t| [ 05 ] - Listar as itens de forma recursiva invertida\t      |\n");
        printf("\t| [ 06 ] - Limpar a lista em memoria\t\t\t      |\n");
        printf("\t| [ 07 ] - Salvar lista em arquivo texto\t\t      |\n");
        printf("\t| [ 08 ] - Contar items e memoria\t\t\t      |\n");
        printf("\t| [ 09 ] - Procurar item por data\t\t\t      |\n");
        printf("\t| [ 10 ] - Sair\t\t\t\t\t\t      |\n");
        printf("\t+-------------------------------------------------------------+\n");
        scanf("%d", &option);
        fflush(stdin);
        if(option > 10 || option < 1){
            system(CLEAR);
            printf("\n\t\aOPCAO INVALIDA!\n\tTENTE DE NOVO!\n");
            getch();
        }
        system(CLEAR);
    } while(option > 10 || option < 1);

    return option;
}

// Função Inicio ponteiro em NULL
Item* start(){
    return NULL;
}

//Função alocar espaço na memória
Item* insert(Item *list, char date[], char name[]){
    Item *novo = (Item*) malloc (sizeof(Item));
    if(novo == NULL){
		printf("\n\t\aSem memoria disponivel!\n");
		exit(1);
	}
    strcpy(novo->date, date);
    strcpy(novo->name, name);
	novo->next = list;
	return novo;
}

//Função para impressão iterativa
void print(Item * list){
    if (list == NULL){
        printf("\n\t\aSEM REGISTRO!\n");
        getch();
        return;
    }
    while(list != NULL){
		printf("Data: %s\nNome: %s\n\n", list->date, list->name);
		list = list->next;
	}
	getch();
}

//Função para impressão recursiva
void printRecursive(Item* list){
	if(list == NULL){
		return;
	}
	else{
		printf("Data: %s\nNome: %s\n\n", list->date, list->name);
		printRecursive(list->next);
	}
}

//Função para impressão Recursiva invertida
void printRecursiveInverted(Item* list){
	if(list == NULL){
		return;
	}
	else{
		printRecursiveInverted(list->next);
		printf("Data: %s\nNome: %s\n\n", list->date, list->name);
	}
}

//Função para inserir um item manual
void inserirItem(Item *list, char *date, char *name){
    fflush(stdin);
    printf("Digite a data: ");
    gets(date);
    //fgets(date, sizeof(date), stdin);
    fflush(stdin);
    printf("Digite o nome da serie/filme: ");
    gets(name);
    //fgets(name, 100, stdin);;
}

// Função para salvar em arquivo TXT
int save(Item *list){
    FILE *file;
    char txt[50], opt;
    printf("Informe o nome do arquivo que deseja salvar (TXT): ");
    gets(txt);
    file = fopen(txt, "a");
    fflush(stdin);
    if(file == NULL){
        printf("\n\t\aErro %d - %s\n", errno, strerror(errno));
        getch();
        return 0;
    } else {
        system(CLEAR);
        printf("Arquivo %s ja existe.\nDeseja Sobrescrever [S] ou Atualizar [A]: ", txt);
        scanf("%c", &opt);
        if (opt == 'S' || opt == 's'){
            file = fopen(txt, "w");
        }
    }
    while(list != NULL){
		fprintf(file, "%s;%s\n", list->date, list->name);
		list = list->next;
	}
    fclose(file);
    printf("\n\t\aARQUIVO %s SALVO COM SUCESSO!\n", txt);
    getch();
}

// Função abrir arquivo de TXT e enviar para a memoria
Item* load(Item *list){
    char date[11], name[100];
    FILE *file;
    fflush(stdin);
    printf("Informe o nome do arquivo (.txt): ");
    gets(arq);
    file = fopen(arq, "r");

    if(file == NULL){
        printf("\n\t\aErro %d - %s\n", errno, strerror(errno));
        getch();
        return 0;
    }
    cont = 0; //contador de resgistros inicializando em 0
    fseek(file, 0, SEEK_END); //Fseek para percorrer com o ponteiro *file até o final do arquivo
    tam = ftell(file); //Ftell retornando o tamanho em bytes do aquivo *file e atribuindo à variável global tam
    rewind(file); // Retornando ao inicio do ponteiro *file.
    system(CLEAR);

    free(list); // Liberando a memoria para a abertura do arquivo
    list = start(); // Inicializando lista em NULL
    while (fscanf(file, "%[^;];%[^\n]\n", date, name) == 2){
        list = insert(list, date, name); // Adicionando à lista encadeado todos os registros lidos no arquivo TXT
        cont++; // contador incrementa a cada registro encontrado
    }
    printf("\n\t\aLEITURA REALIZADA COM SUCESSO!\n");
    fclose(file);
    getch();
    return list;
}

// Função limpar lista e memória
void destroy (Item *list){
    if (list != NULL){
        free(list);
        printf("\n\t\aMEMORIA ESVAZIADA COM SUCESSO!\n");
        getch();
    } else {
        printf("\n\t\aMEMORIA VAZIA!\n");
        getch();
    }
 }

 // Função buscar registro por data
void search(Item * list){
    char date[10];
    if (list == NULL){
        printf("\n\t\aSEM REGISTRO!\n");
        getch();
        return;
    }
    printf("Digite a data que deseja buscar DD/MM/AAAA: ");
    fgets(date, 11, stdin);
    printf("\n");
    while(list != NULL){
        if(strcmp(date, list->date) == 0){
            printf("Data: %s\nNome: %s\n\n", list->date, list->name);
        }
		list = list->next;
	}
	getch();
}

