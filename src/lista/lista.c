#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/********************************* Inserir ***********************************************/
extern Fita *memoria;

void inserir()
{
    if (memoria->ocupado >= TAM_MEMORIA)
    {
        printf("Poxa, a lista já está cheia... Remova algum arquivo primeiro :(");
        sleep(3);
        return;
    }

    char bloco[100];
    char nome_arquivo[50];
INICIO:
    do
    {
        system("clear");
        printf("\nDigite o nome do aquivo: ");
        scanf("%s", nome_arquivo);
        FILE *arquivo = fopen(nome_arquivo, "r");

        if (arquivo == NULL)
        {
            printf("Arquivo não encontrado... Tem certeza que colocou o nome certo?");
            sleep(2);
            goto INICIO;
        }
        while (!feof(arquivo))
        {
            fgets(bloco, 100, arquivo);
            Bloco *novo_no = (Bloco *)malloc(sizeof(Bloco)); // define o próximo nó

            strcpy(novo_no->arquivo, bloco);
            //strcpy(novo_no->nome_arquivo, nome_arquivo);

            //novo_no->indice = NULL;

           /* if (memoria->tam == 0)
            {
                memoria->cab = novo_no;
                memoria->ret = memoria->cab;
            }
            else
            {
                memoria->ret->indice = novo_no;
                memoria->ret = novo_no;
            }*/

            memoria->ocupado++;
        }
        printf("Arquivo inserido perfeitamente! :)\n");
        sleep(3);
        system("clear");

        break;

    } while (1);
}

/********************************* Remover ***********************************************/

void remover(int menu)
{
    buscar(menu);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
    
}

/********************************* Buscar ***********************************************/

StructBusca *buscar(int menu)
{
    /*char chave[50];
    StructBusca * remove_arquivo = (StructBusca *)malloc(sizeof(StructBusca));
    Bloco *no_atual = memoria->cab;
    Bloco *no_anterior = NULL;

    system("clear");

    printf("Digite o nome arquivo: ");
    scanf("%s", chave);

    if (no_atual == NULL)
    {
        printf("\nA lista está vazia...\nQue tal adicionar um arquivo através da opção (1) do menu?\n");
        sleep(4);
        return NULL;
    }

    while (no_atual != NULL && strcmp(no_atual->nome_arquivo, chave) != 0)
        no_anterior = no_atual;
       // no_atual = no_atual -> indice;

    if (no_atual != NULL)
    {
        if (menu == 3)
            printar_arquivo(memoria, no_atual);
        if(menu == 2)
        {
            printf("\nArquivo encontrado...");
            remove_arquivo -> ant = no_anterior;
            remove_arquivo -> atual = no_atual;
            return remove_arquivo;
        }
    }
    else
    {*/
        printf("O arquivo não está aqui :(\nQue tal procurar por outro?\n");
        sleep(4);
    //}
}

/******************************* Imprimir a lista *********************************************/

void printar()
{
    system("clear");
    int cont = 0;

    while (memoria->blocos[cont]->indice_prox > TAM_MEMORIA)
    {
        if (memoria->blocos != NULL){
        printf("-> Bloco %d\nNome do arquivo: %s\nEndereço: %p\n", cont, memoria->blocos[cont]->nome_arquivo, memoria->blocos);
        printf("Conteúdo do arquivo: %s\n\n", memoria->blocos[cont]->arquivo);
        cont++;
        memoria->ocupado++;
        }
    }
    printf("\nPorcentagem ocupada de memória: %d\n\n", memoria->ocupado);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();
}

/******************************* Imprimir arquivo *********************************************/



void printar_arquivo(Bloco *no_atual)
{
    system ("clear");
    printf("Achei! O arquivo está aqui:\n");
    /*No *cab = lista_encadeada->cab;
    int cont = 1;

    while (no_atual == 1) 
    {
        printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", cont, cab->nome_arquivo, cab);
        printf("Conteúdo do arquivo: %s\n\n", cab->arquivo);
        cab = cab->prox;
        cont++;
    }
    printf("\nTamanho da lista: %d\n\n", lista_encadeada->tam);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();*/
}

