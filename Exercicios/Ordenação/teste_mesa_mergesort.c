#include <stdio.h>
int passo = 0;
/**
  * Exemplo de Implementação do Método de Ordenação MergeSort
  * Diogo Cezar <diogo@diogocezar.com>
  */

void intercala(int x[], int inicio, int fim, int meio);

/**
  * Ordenação pelo método MergeSort
  */
void mergeSort(int x[], int inicio, int fim){
    int meio;
    /**
    * a condição de parada é que o início seja menor que o fim.
    * estes índices vão se aproximando recursivamente.
    * quando a condição não é satisfeita, volta-se na árvore de recursividade.
    * notem: a recursividade é chamada 2 vezes, uma para do início ao meio outra para o meio+1 até o fim
    */
    if (inicio < fim){
        passo++;
        meio = ((inicio + fim) / 2);
        printf("\n|%d\t|%d\t|%d\t|%d\t|", passo, inicio, meio, fim);
        setbuf(stdin, NULL);
        /*getchar();*/
        mergeSort(x, inicio, meio);
        passo++;
        printf("\n|%d\t|%d\t|%d\t|%d\t|", passo, inicio, meio, fim);
        setbuf(stdin, NULL);
        /*getchar();*/
        mergeSort(x, (meio + 1), fim);
        passo++;
        printf("\n|%d\t|%d\t|%d\t|%d\t|", passo, inicio, meio, fim);
        setbuf(stdin, NULL);
        /*getchar();*/
        intercala(x, inicio, fim, meio);
        passo++;
        printf("\n|%d\t|%d\t|%d\t|%d\t|", passo, inicio, meio, fim);
        setbuf(stdin, NULL);
        /*getchar();*/
    }
}

/**
  * este é o método que realiza a intercalação ordenada dos elementos do vetor.
  * é aqui onde dados os índices do vetor, início, fim e meio, o vetor se reorganiza;
  * notem que o vetor é sempre o mesmo
  * o que se altera em cada chamada são os índices
  * este função deve: reordenar o vetor utilizando os índices passados, dando origem a um terceiro vetor ordenado
  */
void intercala(int x[], int inicio, int fim, int meio){
    int poslivre, inicio_v1, inicio_v2, i;
    /**
    * este vetor auxiliar deve ter o mesmo tamanho do vetor original
    */
    int aux[10];
    inicio_v1 = inicio;
    inicio_v2 = meio + 1;
    poslivre = inicio;
    while ((inicio_v1 <= meio) && (inicio_v2 <= fim)){
        if (x[inicio_v1] <= x[inicio_v2]){
            aux[poslivre] = x[inicio_v1];
            inicio_v1 = inicio_v1 + 1;
        }
        else{
            aux[poslivre] = x[inicio_v2];
            inicio_v2 = inicio_v2 + 1;
        }
        poslivre = poslivre + 1;
    }
    /**
    * números que ainda não foram intercalados no vetor 1
    */
    for (i = inicio_v1; i <= meio; i++){
        aux[poslivre] = x[i];
        poslivre = poslivre + 1;
    }
    /**
    * números que ainda não foram intercalados no vetor 2
    */
    for (i = inicio_v2; i <= fim; i++){
        aux[poslivre] = x[i];
        poslivre = poslivre + 1;
    }
    /**
    * retorna os valores de aux para o vetor x
    */
    for (i = inicio; i <= fim; i++){
        x[i] = aux[i];
    }
}

/**
  * Impressão de um vetor
  */
void printVet(int n, int v[]){
    int j;
    for(j = 0; j<n ; j++){
        printf("[%d] ", v[j]);
    }
    printf("\n");
}

/**
  * Função Principal
  */
int main(){
    int v[6] = {80,12,1,3,40,20};
    //int v[7] = {80,12,1,5,18,20,3};
    /* note que x tem que ter as duas metades ordenadas! */
    /* 1, 12, 18 */
    /* 3, 5, 20, 80 */
    int x[6] = {12,80,1,3,20,40};
    //int x[7] = {1,12,18,3,5,20,80};
    printf("Vetor original:\n");
    printVet(6, v);
    printf("\n+-------------------------------+");
    printf("\n|Passo\t|inicio\t|meio\t|fim\t|");
    printf("\n+-------------------------------+");
    mergeSort(v, 0, 5);
    printf("\n+-------------------------------+");
    printf("\n\nVetor ordenado:\n");
    printVet(6, v);
    printf("\nTestando intercalacao para {1,12,18,3,5,20,80} :\n\n");
    printVet(6, x);
    intercala(x, 0, 5, 1);
    printVet(6, x);
}