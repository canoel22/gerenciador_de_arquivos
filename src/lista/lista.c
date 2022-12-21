#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/********************************* Inserir ***********************************************/

void inserir(Lista *lista_encadeada)
{
    if (lista_encadeada->tam >= 1000)
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
            No *novo_no = (No *)malloc(sizeof(No)); // define o próximo nó

            strcpy(novo_no->arquivo, bloco);
            strcpy(novo_no->nome_arquivo, nome_arquivo);

            novo_no->prox = NULL;

            if (lista_encadeada->tam == 0)
            {
                lista_encadeada->cab = novo_no;
                lista_encadeada->ret = lista_encadeada->cab;
            }
            else
            {
                lista_encadeada->ret->prox = novo_no;
                lista_encadeada->ret = novo_no;
            }

            lista_encadeada->tam++;
        }
        printf("Arquivo inserido perfeitamente! :)\n");
        sleep(3);
        system("clear");

        break;

    } while (1);
}

/********************************* Remover ***********************************************/

void remover(Lista *lista_encadeada, int menu)
{
    buscar(lista_encadeada, menu);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
    
}

/********************************* Buscar ***********************************************/

StructBusca *buscar(Lista *lista_encadeada, int menu)
{
    char chave[50];
    StructBusca * remove_arquivo = (StructBusca *)malloc(sizeof(StructBusca));
    No *no_atual = lista_encadeada->cab;
    No *no_anterior = NULL;

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
        no_atual = no_atual -> prox;

    if (no_atual != NULL)
    {
        if (menu == 3)
            printar_arquivo(lista_encadeada, no_atual);
        if(menu == 2)
        {
            printf("\nArquivo encontrado...");
            remove_arquivo -> ant = no_anterior;
            remove_arquivo -> atual = no_atual;
            return remove_arquivo;
        }
    }
    else
    {
        printf("O arquivo não está aqui :(\nQue tal procurar por outro?\n");
        sleep(4);
    }
}

/******************************* Imprimir a lista *********************************************/

void printar(Lista *lista_encadeada)
{
    system("clear");

    No *cab = lista_encadeada->cab;
    int cont = 1;

    while (cab != NULL)
    {
        printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", cont, cab->nome_arquivo, cab);
        printf("Conteúdo do arquivo: %s\n\n", cab->arquivo);
        cab = cab->prox;
        cont++;
    }
    printf("\nTamanho da lista: %d\n\n", lista_encadeada->tam);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();
}

/******************************* Imprimir arquivo *********************************************/



void printar_arquivo(Lista *lista_encadeada, No *no_atual)
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

