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

/// @brief estrutura de cada bloco de memória que guarda conteúdo dos arquivos
typedef struct Bloco
{ 
    char arquivo[TAM_MEMORIA];
    int indice_prox;
    char nome_arquivo[TAM_NOME];
} Fita;

/// @brief estrutura para guardar informações de cada arquivo
typedef struct
{ 
    int qtd_blocos;
    char nome_arquivo[TAM_NOME];
    int indice_inicial;
} Arquivos;

/********************************* Funções ***********************************************/

/// @brief limpa o vetor para não haver chance de armazenar algum lixo
/// @param memoria vetor que armazena os arquivos
void limpar_memoria(Fita **memoria);

/// @brief limpa o vetor para não haver chance de armazenar algum lixo
/// @param lista vetor que armazena as informações de cada arquivo
void limpar_lista(Arquivos **lista);


/// @brief verifica se a quantidade de blocos livres é >= à quantidade necessária de blocos para inserir o novo arquivo arquivo
/// @param memoria é onde os arquivos estão cadastrados
/// @param blocos_ocupados é a % dos blocos ocupados de memória
/// @param nome_arquivo recebe o nome do arquivo para abrir e ver quantos blocos ele irá ocupar
/// @return retorna 1 caso seja possível a inserção e 0, caso não
int pode_inserir(Fita **memoria, int *blocos_ocupados, char *nome_arquivo);

/// @brief insere (ou não) o arquivo nos blocos e atualiza a lista de arquivos
/// @param memoria é onde os arquivos estão cadastrados
/// @param blocos_ocupados aumenta a quantidade de blocos ocupados na memória
/// @param lista é onde os dados do arquivo inserido serão armazenados
void inserir(Fita **memoria, int *blocos_ocupados, Arquivos **lista);

/// @brief divide o arquivo em blocos e os cadastra na memória
/// @param memoria é onde os arquivos serão cadastrados
/// @param bloco é onde guardamos partes de texto dos arquivos
/// @param nome_arquivo recebe a string para abrir o arquivo
/// @param blocos_ocupados  usa a % dos blocos ocupados para fazer as verificações
/// @return retorna 1 caso possa inserir e 0 caso não
int inserir_bloco(Fita **memoria, char *bloco, char *nome_arquivo, int *blocos_ocupados);

/// @brief busca um arquivo na lista de arquivos
/// @param memoria é onde os arquivos estão cadastrados
/// @param lista é onde os dados dos arquivos estão cadastrados (que usaremos para procurar na memória)
/// @param menu dependendo da escolha do usuário, ele pode printar a lista (busca) ou só retornar o nó atual(remoção)
/// @return retorna o nó da lista contendo as informações para encontrá-lo na memoria ou NULL
Arquivos *buscar(Fita **memoria, Arquivos **lista, int menu);

/// @brief printa a fita de memória, com todos os arquivos armazenados e algumas informações sobre eles
/// @param memoria é onde o conteúdo/informações dos arquivos estão armazenados
void printar_fita(Fita **memoria);

/// @brief printa a lista dos arquivos cadastrados, com algumas informações essenciais para encontrá-los
/// @param lista é onde os dados de cada arquivo estão cadastrados
void printar_lista(Arquivos **lista);

/// @brief printa apenas o arquivo selecionado na função buscar
/// @param memoria é de onde as informações que serão printadas sairão
/// @param no_atual recebe as informações necessárias do nó armazenado na lista para achar o elemento na memória
void printar_arquivo(Fita **memoria, Arquivos *no_atual);

/// @brief remove um arquivo desejado
/// @param memoria remove da memória os n blocos em que o arquivo está dividido
/// @param lista  remove a lista[x] que contém os dados do arquivo
/// @param menu recebe o num do menu escolhido pelo usuário para usar na função buscar
/// @param blocos_ocupados diminui a quantidade de blocos ocupados na memória
void remover(Fita **memoria, Arquivos **lista, int menu, int *blocos_ocupados);

#endif