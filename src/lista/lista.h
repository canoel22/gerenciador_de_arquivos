#ifndef __lista_h
#define __lista_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/******************************* Estruturas ***********************************************/

typedef struct no {    //estrutura de cada bloco de memória
    char arquivo[100];
    int indice; 
} Bloco;

typedef struct{     //estrutura da fita de memória
   int tam;
   Bloco 
} Fita;

typedef struct {    //estrutura para a função de busca retornar dois nós
    Bloco* ant;
    Bloco* atual;
} StructBusca;

/********************************* Funções ***********************************************/

void printar(Fita *lista_encadeada);
void printar_arquivo(Fita *lista_encadeada, Bloco *no_atual);
void inserir(Fita* lista_encadeada);
void remover(Fita* lista_encadeada, int menu);
StructBusca *buscar(Fita* lista_encadeada, int menu);
void printar_arquivo(Fita *lista_encadeada, bloco *no_atual);

#endif