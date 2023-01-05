#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/********************************* Inserir ***********************************************/

void inserir(Fita *memoria)
{
    if (memoria->tam >= 1000)
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
            Bloco *novo_no = (Bloco *)malloc(sizeof(No)); // define o próximo nó

            strcpy(novo_no->arquivo, bloco);
            //strcpy(novo_no->nome_arquivo, nome_arquivo);

            novo_no->indice = NULL;

            if (memoria->tam == 0)
            {
                memoria->cab = novo_no;
                memoria->ret = memoria->cab;
            }
            else
            {
                memoria->ret->indice = novo_no;
                memoria->ret = novo_no;
            }

            memoria->tam++;
        }
        printf("Arquivo inserido perfeitamente! :)\n");
        sleep(3);
        system("clear");

        break;

    } while (1);
}

/********************************* Remover ***********************************************/

void remover(Fita *lista_encadeada, int menu)
{
    buscar(lista_encadeada, menu);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
    
}

/********************************* Buscar ***********************************************/

StructBusca *buscar(Fita *memoria, int menu)
{
    char chave[50];
    StructBusca * remove_arquivo = (StructBusca *)malloc(sizeof(StructBusca));
    No *no_atual = memoria->cab;
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
        no_atual = no_atual -> indice;

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
    {
        printf("O arquivo não está aqui :(\nQue tal procurar por outro?\n");
        sleep(4);
    }
}

/******************************* Imprimir a lista *********************************************/

void printar(Fita *lista_encadeada)
{
    system("clear");

    No *cab = lista_encadeada->cab;
    int cont = 1;

    while (cab != NULL)
    {
        printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", cont, cab->nome_arquivo, cab);
        printf("Conteúdo do arquivo: %s\n\n", cab->arquivo);
        cab = cab->indice;
        cont++;
    }
    printf("\nTamanho da lista: %d\n\n", lista_encadeada->tam);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();
}

/******************************* Imprimir arquivo *********************************************/



void printar_arquivo(Fita *lista_encadeada, No *no_atual)
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
