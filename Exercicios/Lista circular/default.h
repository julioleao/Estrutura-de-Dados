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

// Funcao menu principal
int menu(int *opt){
	printf("+-------------------------------------------------------+\n");
	printf("| [1] - Inserir de forma ordenada                       |\n");
	printf("| [2] - Inserir no fim de uma lista                     |\n");
	printf("| [3] - Encontrar o maior elemento                      |\n");
	printf("| [4] - Encontrar o menor elemento                      |\n");
	printf("| [5] - Remover do inicio                               |\n");
	printf("| [6] - Remover do fim                                  |\n");
	printf("| [7] - Imprimir a lista                                |\n");
	printf("| [0] - Voltar                                          |\n");
	printf("+-------------------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}

int menu2(int *opt){
	system(CLEAR);
	printf("+------------------------------------------+\n");
	printf("|                   MENU                   |\n");
	printf("+------------------------------------------+\n");
	printf("| [1] - Lista simplesmente encadeada       |\n");
	printf("| [2] - Lista duplamente encadeada         |\n");
	printf("| [3] - Lista circular                     |\n");
	printf("| [0] - Sair                               |\n");
	printf("+------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}

int menu3(int *opt){
	system(CLEAR);
	printf("+------------------------------------------+\n");
	printf("|      LISTA CIRCULAR - MEDIA VALORES      |\n");
	printf("+------------------------------------------+\n");
	printf("| [1] - Inserir elemento                   |\n");
	printf("| [2] - Imprimir lista                     |\n");
	printf("| [3] - Remover um elemento da lista       |\n");
	printf("| [4] - Imprimir a media total             |\n");
	printf("| [0] - Sair                               |\n");
	printf("+------------------------------------------+\n");
	printf("\nInforme uma opcao: ");
	scanf("%d", opt);
	system(CLEAR);
	return *opt;
}


void errorMsg(){
	printf("\n\t+--------------------+\n");
	printf("\t|   OPCAO INVALIDA   |\n");
	printf("\t+--------------------+\n");
}

void byeMsg(){
	printf("\n\t+-------------------------------------+\n");
	printf("\t|   VALEU, FALOU E ATE....ATE MAIS.   |\n");
	printf("\t+-------------------------------------+\n\n");
}
