#ifndef __lista_h
#define __lista_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM_ARQUIVO 100
#define TAM_MEMORIA 100

/******************************* Estruturas ***********************************************/

typedef struct no {    //estrutura de cada bloco de memória
    char arquivo[TAM_ARQUIVO];
    char nome_arquivo[50];
    int indice_prox; 
} Bloco;

typedef struct{     //estrutura da fita de memória
   Bloco blocos[TAM_MEMORIA];
   int ocupado;
} Fita;

typedef struct {    //estrutura para a função de busca retornar dois blocos
    Bloco* ant;
    Bloco* atual;
} StructBusca;

/********************************* Funções ***********************************************/

void printar();
void printar_arquivo(Bloco *no_atual);
void inserir();
void remover(int menu);
StructBusca *buscar(int menu);
void printar_arquivo(Bloco *no_atual);

#endif