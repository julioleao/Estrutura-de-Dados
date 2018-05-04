/*
 *
 *
  Nome: Julio Cesario de Paiva Leão
  RA: 1916033
  Estrutura de Dados
  Engenharia de Software 2018/01
  
  crie uma versão dinâmica para a lista circular;
  implemente as funções de:
    enfileirar
    desenfileirar
    imprimir
    buscar por um elemento
  você pode escolher a linguagem que desenvolverá a estrutura;

 *
 *
 */


#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

// Struct definindo frente, tras e o vetor
typedef struct Cq{
    int Front,Rear;
    int Arr[SIZE];
}Cq;

// Struct para alocação dinamica da Fila circular
Cq* Make(){
    Cq* New=(Cq*)malloc(sizeof(Cq));
    New->Front=-1;
    New->Rear=-1;
    return New;
}


// Função para inserir elementos na fila circular
void insertElement(Cq* Q,int X){
    if(Q->Front==-1 && Q->Rear==-1)
        Q->Front=Q->Rear=0;

    else if((Q->Rear==SIZE-1 && Q->Front==0) || (Q->Rear==Q->Front-1)){
        printf("\nFila esta cheia\n");
        return;
    }

    else if(Q->Rear==SIZE-1)
        Q->Rear=0;

    else
        Q->Rear++;

    Q->Arr[Q->Rear]=X;
}

// Função para deletar elementos na fila circular
void deleteElement(Cq* Q){
    if(Q->Front==-1 && Q->Rear==-1){
        printf("\nFila esta vazia\n");
        return;
    }
    else if(Q->Front==Q->Rear)
        Q->Front=Q->Rear=-1;
    else if(Q->Front==SIZE-1)
        Q->Front=0;
    else
        Q->Front++;
    printf("\nElemento removido!\n");
}

// Função para imprimir elementos da fila circular
void displayQueue(Cq* Q){
    int I;

    if(Q->Front==-1){
        printf("\nFila esta vazia\n");
        return;
    }
    else{
        printf("\n");
        if(Q->Front<=Q->Rear){
            for(I=Q->Front;I<=Q->Rear;I++)
            printf("Elemento: %d\n",Q->Arr[I]);
        }else{
            for(I=Q->Front;I<=SIZE-1;I++)
            printf("Elemento: %d\n",Q->Arr[I]);

            for(I=0;I<=Q->Rear;I++)
            printf("Elemento: %d\n",Q->Arr[I]);
        }
    }
}

// Função para buscar um elemento na fila circular
void searchQueue(Cq* Q, int X){
    int I;

    if(Q->Front==-1){
        printf("\nFila esta vazia\n");
        return;
    }
    else{
        printf("\n");
        if(Q->Front<=Q->Rear){
            for(I=Q->Front;I<=Q->Rear;I++){
                if(Q->Arr[I] == X){
                    printf("Elemento %d encontrado!\n",X);
                    return;
                }  
            }
        }else{
            for(I=Q->Front;I<=SIZE-1;I++){
                if(Q->Arr[I] == X){
                    printf("Elemento %d encontrado!\n",X);
                    return;
                }  
            }
            for(I=0;I<=Q->Rear;I++){
                if(Q->Arr[I] == X){
                    printf("Elemento %d encontrado!\n",X);
                    return;
                }  
            }
        }
    }
    printf("Elemento %d NAO encontrado!\n",X);
}


// Função principal
int main(){
    Cq* Cq1=Make();

    insertElement(Cq1,4);
    insertElement(Cq1,7);
    insertElement(Cq1,2);
    insertElement(Cq1,5);

    displayQueue(Cq1);

    searchQueue(Cq1, 4);

    deleteElement(Cq1);

    displayQueue(Cq1);

    searchQueue(Cq1, 4);

    deleteElement(Cq1);

    displayQueue(Cq1);

    deleteElement(Cq1);

    displayQueue(Cq1);

    deleteElement(Cq1);

    return 0;
}