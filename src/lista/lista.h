#ifndef __lista_h
#define __lista_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/******************************* Estruturas ***********************************************/

typedef struct _no {    //estrutura de cada nó
    char nome_arquivo[50];
    char arquivo[100];
    struct _no* prox;
} No;

typedef struct{     //estrutura da lista (cabeça e retaguarda)
    No* cab;
    No* ret;
    int tam;
} Lista;

typedef struct {    //estrutura para a função de busca retornar dois nós
    No* ant;
    No* atual;
} StructBusca;

/********************************* Funções ***********************************************/

void printar(Lista *lista_encadeada);
void printar_arquivo(Lista *lista_encadeada, No *no_atual);
void inserir(Lista* lista_encadeada);
void remover(Lista* lista_encadeada, int menu);
StructBusca *buscar(Lista* lista_encadeada, int menu);
void printar_arquivo(Lista *lista_encadeada, No *no_atual);

#endif