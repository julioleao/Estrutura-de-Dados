#include <stdio.h>
#include <stdlib.h>

// Hack para limpar a tela
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Estrutura FichaCliente usada para preenchimento.
typedef struct FichaCliente{
    char name[50];
    char street[50];
    int number;
    char city[30];
    char state[30];
    char cep[9];
}FichaCliente;

// Variáveis globais: quant para a 1ª quantidade de registros e newQuant para os demais resgistros.
int quant = 0;
int newQuant = 0;

// Protótipos
void printData(FichaCliente *client);
void readData(FichaCliente *client);
FichaCliente* aloc(FichaCliente *client);
int menu();
FichaCliente* realoc(FichaCliente *client);
void readDataNew(FichaCliente *client);

int main(){
    int quit =1;
    FichaCliente *client;
    system(CLEAR);
    /*
     *
     Programa pede que o usuario realize o primeiro registro, mas para isso
     ele pergunta a quantidade de registros a ser realizada.
     *
     */
    printf("> Informe a quantidade de registros: ");
    scanf("%d", &quant);
    system(CLEAR);
    client = aloc(client);
    fflush(stdin);
    readData(client);
    /*
     *
     Laço Do While realizando loop até que o usuário digite o numero 3 para sair do programa
     Switch chama a função menu, com as opções:
     1 Realizar registro
     2 Listar registros
     3 Sair
     O default retornará uma mensagem de erro caso qualquer outra tecla seja pressionada.
     *
     */
    do{
        switch(menu()){
    
            case 1:
                printf("> Quantos registros deseja realizar?: ");
                scanf("%d", &newQuant);
                realoc(client);
                system(CLEAR);
                readDataNew(client);
                break;
            case 2:
                printData(client);
                getchar();
                printf("Pressione ENTER para continuar...");
                getchar();
                system(CLEAR);
                break;
            case 3:
                printf("+------------------+\n");
                printf("|     ATE MAIS!    |\n");
                printf("+------------------+\n\n");
                free(client);
                quit = 0;
                exit(1);
            default:
                printf("\nOPCAO INVALIDA\n");
                getchar();
                printf("\nPressione ENTER para continuar...");
                getchar();
                system(CLEAR);
                break;
        }
    } while (quit != 0);
    return 0;
}

// Função de menu da navegação
int menu(){
    int option;
    system(CLEAR);
    printf("+--------------------------+\n");
    printf("| [1] Inserir registros    |\n");    
    printf("| [2] Listar cadastrados   |\n");
    printf("| [3] Sair                 |\n");
    printf("+--------------------------+\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &option);
    system(CLEAR);
    return option;    
}

// Função que lê novos dados do usuário, após uma nova realocação na memória
void readDataNew(FichaCliente *client){
    int i;
    
    for (i = quant; i < (quant + newQuant); i++){
        printf("> Informe o nome do cliente %.2d..: ", i+1);
        scanf("%s", client[i].name);
        printf("> Informe o nome da rua.........: ");
        scanf("%s", client[i].street);
        printf("> Informe o numero da rua.......: ");
        scanf("%d", &client[i].number);
        fflush(stdin);
        printf("> Informe a cidade..............: ");
        scanf("%s", client[i].city);
        printf("> Informe o estado..............: ");
        scanf("%s", client[i].state);
        printf("> Informe o CEP.................: ");
        scanf("%s", client[i].cep);
    }
    system(CLEAR);
    quant += newQuant;
    // quant soma-se ao newQuant para se obter o tamanho total do vetor client.
}

// Função que aloca na memória a quantidade inicial de registros
FichaCliente* aloc(FichaCliente *client){
 
    system(CLEAR);
    client = (FichaCliente*) malloc (quant * sizeof(FichaCliente));
    if(client == NULL){
        printf("Erro na alocacao!\n");
        free(client);
        exit(1);
    }
    return client;
}

// Função que realoca na memória a quantidade de registro que o usuário informar
FichaCliente* realoc(FichaCliente *client){
    

    client = (FichaCliente*)realloc (client,(newQuant+quant) * sizeof(FichaCliente));
    printf("%d e %d\n", quant, newQuant);
    if(client == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA\n");
        free(client);
        exit(1);
    }
    system(CLEAR);
    return client;
    
}

// Função que lê os primeiros dados do usuário para utilizar na função malloc
void readData(FichaCliente *client){
    int i;
    for (i = 0; i < quant; i++){
        printf("> Informe o nome do cliente %.2d..: ", i+1);
        scanf("%s", client[i].name);
        printf("> Informe o nome da rua.........: ");
        scanf("%s", client[i].street);
        printf("> Informe o numero da rua.......: ");
        scanf("%d", &client[i].number);
        fflush(stdin);
        printf("> Informe a cidade..............: ");
        scanf("%s", client[i].city);
        printf("> Informe o estado..............: ");
        scanf("%s", client[i].state);
        printf("> Informe o CEP.................: ");
        scanf("%s", client[i].cep);
    }
    system(CLEAR);
}

// Função que imprime na tela todos os usuários cadastrados
void printData(FichaCliente *client){
    int i;
    for (i = 0; i < quant; i++){
        printf("+---------------------->\n");
        printf("| Cliente %.2d..: %s\n", i+1, client[i].name);
        printf("| Rua.........: %s\n", client[i].street);
        printf("| Numero......: %d\n", client[i].number);
        printf("| Cidade......: %s\n", client[i].city);
        printf("| Estado......: %s\n", client[i].state);
        printf("| CEP.........: %s\n", client[i].cep);
        printf("+------------------------------->\n");
    }
    
}


