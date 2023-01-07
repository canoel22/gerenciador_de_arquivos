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

void inserir(Fita** memoria, int *blocos_ocupados, Arquivos **lista);
int inserir_bloco(Fita** memoria, char* bloco, char* nome_arquivo, int* blocos_ocupados);

int *buscar(Fita** memoria, int menu, Arquivos **lista);

void printar(Fita **memoria);
void printar_arquivo(Fita **memoria, Fita *no_atual);
void remover(Fita** memoria, int menu);

void printar_arquivo(Fita** memoria, Fita *no_atual);

#endif