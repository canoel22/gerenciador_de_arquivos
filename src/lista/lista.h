#ifndef __lista_h
#define __lista_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM_MEMORIA 100
#define TAM_NOME 50
#define TAM_BLOCO 100

/******************************* Estruturas ***********************************************/

typedef struct Bloco {    //estrutura de cada nó
    char arquivo[TAM_MEMORIA];
    int indice_prox;
    char nome_arquivo[TAM_NOME];
} Fita;


/*typedef struct {    //estrutura para a função de busca retornar dois nós
    No* ant;
    No* atual;
} StructBusca;*/

/********************************* Funções ***********************************************/

void limpar_memoria(Fita** memoria);
int pode_inserir(Fita **memoria, FILE *arquivo, char *bloco, int blocos_ocupado);
void printar(Fita **memoria);
void printar_arquivo(Fita **memoria, Fita *no_atual);
void inserir(Fita** memoria, int blocos_ocupados);
void remover(Fita** memoria, int menu);
//StructBusca *buscar(Fita** memoria, int menu);
void printar_arquivo(Fita** memoria, Fita *no_atual);

#endif