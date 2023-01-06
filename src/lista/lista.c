#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void limpar_memoria(Fita **memoria)
{
    for (int i = 0; i < TAM_BLOCO; i++)
    {
        memoria[i] = NULL;
    }
}

/********************************* Inserir ***********************************************/

int pode_inserir(Fita **memoria, FILE *arquivo, char *bloco, int blocos_ocupados)
{
    int cont = 0;

    while (fgets(bloco, TAM_BLOCO, arquivo))
    {
        cont++;
    }

    if (cont <= (TAM_MEMORIA - blocos_ocupados))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir(Fita **memoria, int blocos_ocupados)
{
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
            if (pode_inserir(memoria, arquivo, bloco, blocos_ocupados))
            {
                Fita *memoria = (Fita *)malloc(sizeof(Fita)); // define o próximo bloco

                fseek(arquivo, 0, SEEK_SET); // move o cursor pro inicio do arquivo
                fgets(bloco, TAM_BLOCO, arquivo);

                strcpy(memoria->arquivo, bloco);
                strcpy(memoria->nome_arquivo, nome_arquivo);

                printf("Arquivo inserido perfeitamente! :)\n");
                sleep(3);
                system("clear");
                break;
            }
            else
            {
                printf("Poxa, não tenho memória suficente pra inserir esse arquivo... Remova algum arquivo primeiro :(");
                sleep(3);
                return;
            }
            break;
        }
    } while (1);
}

/********************************* Remover ***********************************************/

void remover(Fita **memoria, int menu)
{
    //buscar(memoria, menu);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
}

/********************************* Buscar ***********************************************/

/*StructBusca *buscar(Fita **memoria, int menu)
{
   /* char chave[50];
    StructBusca *remove_arquivo = (StructBusca *)malloc(sizeof(StructBusca));
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
    no_atual = no_atual->indice;

    if (no_atual != NULL)
    {
        if (menu == 3)
            printar_arquivo(memoria, no_atual);
        if (menu == 2)
        {
            printf("\nArquivo encontrado...");
            remove_arquivo->ant = no_anterior;
            remove_arquivo->atual = no_atual;
            return remove_arquivo;
        }
    }
    else
    {
        printf("O arquivo não está aqui :(\nQue tal procurar por outro?\n");
        sleep(4);
    }*/
//}

/******************************* Imprimir a lista *********************************************/

void printar(Fita **memoria)
{
   /* system("clear");

    No *cab = memoria->cab;
    int cont = 1;

    while (cab != NULL)
    {
        printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", cont, cab->nome_arquivo, cab);
        printf("Conteúdo do arquivo: %s\n\n", cab->arquivo);
        cab = cab->indice;
        cont++;
    }
    printf("\nTamanho da lista: %d\n\n", memoria->tam);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();*/
}

/******************************* Imprimir arquivo *********************************************/

void printar_arquivo(Fita **memoria, Fita *no_atual)
{
    /*system("clear");
    printf("Achei! O arquivo está aqui:\n");
    /*No *cab = memoria->cab;
    int cont = 1;

    while (no_atual == 1)
    {
        printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", cont, cab->nome_arquivo, cab);
        printf("Conteúdo do arquivo: %s\n\n", cab->arquivo);
        cab = cab->prox;
        cont++;
    }
    printf("\nTamanho da lista: %d\n\n", memoria->tam);

    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();*/
}
