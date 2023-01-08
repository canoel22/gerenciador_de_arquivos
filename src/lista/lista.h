#ifndef __lista_h
#define __lista_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM_MEMORIA 100
#define TAM_NOME 50
#define TAM_BLOCO 100

static int arquivo_indice1;

/******************************* Estruturas ***********************************************/

typedef struct Bloco {    //estrutura de cada nó
    char arquivo[TAM_MEMORIA];
    int indice_prox;
    char nome_arquivo[TAM_NOME];
} Fita;


typedef struct {    //estrutura para guardar informações do arquivo
    int qtd_blocos;
    char nome_arquivo[TAM_NOME];
    int indice_inicial;
} Arquivos;

/********************************* Funções ***********************************************/

void limpar_memoria(Fita** memoria);
void limpar_lista(Arquivos **lista);

void inserir(Fita** memoria, int *blocos_ocupados, Arquivos **lista, int menu);
int inserir_bloco(Fita** memoria, char* bloco, char* nome_arquivo, int* blocos_ocupados);

Arquivos *buscar(Fita** memoria, Arquivos **lista, int menu);

void printar_fita(Fita **memoria);
void printar_lista(Arquivos **lista);
void printar_arquivo(Fita **memoria, Arquivos *no_atual);

void remover(Fita **memoria, Arquivos **lista, int menu, int *blocos_ocupados);

#endif