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
void inserir(Fita** memoria, int *blocos_ocupados, Arquivos **lista) {

    char nome_arquivo[TAM_NOME];
    char bloco[TAM_BLOCO];
    int cont = 0;
    FILE* arquivo;
    do
    {
        system("clear");
        printf("Digite o nome do arquivo que deseja inserir: ");
        scanf("%s", nome_arquivo);
        arquivo = fopen(nome_arquivo, "r");

        if (arquivo == NULL) {
            printf("Arquivo não encontrado... Tem certeza que colocou o nome certo?\n");
            sleep(2);
            continue;
        }

        while (!feof(arquivo)) {
            fgets(bloco, TAM_BLOCO, arquivo);
            *blocos_ocupados +=1;
            cont++;

            if(inserir_bloco(memoria, bloco, nome_arquivo, blocos_ocupados) == 0){
                printf("A memória já está cheia...Que tal remover um arquivo antes? :(\n");
                sleep(3);
                fclose (arquivo);
                return;
            }
        }
        break;
    } while (1);

    fclose(arquivo);

    //passando os metadados do arquivo pra lista 2:

    for (int i=0; i<TAM_MEMORIA; i++){
        if (lista[i] == NULL){
            Arquivos *novo_arquivo = (Arquivos*)malloc(sizeof(Arquivos));
            strcpy(novo_arquivo-> nome_arquivo, nome_arquivo);
            novo_arquivo -> qtd_blocos= cont;
            novo_arquivo -> indice_inicial = arquivo_indice1;
            break;
        }
    }

    printf("Aquivo inserido perfeitamente! :)\n");
    sleep(5);
    system("clear");

}


int inserir_bloco(Fita** memoria, char* bloco, char* nome_arquivo, int *blocos_ocupados){
    if (*blocos_ocupados == TAM_MEMORIA) {
        return 0;
    }

    static int no_ant = 0;
    int no_atual = 0;

    while (no_atual < TAM_MEMORIA && memoria[no_atual]->arquivo != NULL) {
        no_atual++;
    }

    memoria[no_atual] = (Fita*)malloc(sizeof(Fita));
    strcpy(memoria[no_atual]->nome_arquivo, nome_arquivo);
    strcpy(memoria[no_atual]->arquivo, bloco);

    if (strcmp(memoria[no_atual]-> nome_arquivo,nome_arquivo) != 0) {
        memoria[no_atual]-> indice_prox = -1;
        no_ant = no_atual;
        arquivo_indice1 = no_atual;
    } else if (no_ant != no_atual) {
        memoria[no_ant]->indice_prox = no_atual;
        no_ant = no_atual;
    }

    blocos_ocupados += 1;
    return 1;

}
/********************************* Remover ***********************************************/

void remover(Fita **memoria, int menu)
{
    //buscar(memoria, menu);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
}

/********************************* Buscar ***********************************************/

int *buscar(Fita **memoria, int menu, Arquivos **lista)
{
    char chave[50];
    int i = 0;
    Arquivos *no_atual = lista[i]; 

    system("clear");

    printf("Digite o nome arquivo: ");
    scanf("%s", chave);

    if (no_atual == NULL)
    {
        printf("\nA lista está vazia...\nQue tal adicionar um arquivo através da opção (1) do menu?\n");
        sleep(4);
        return 0;
    }

    while (no_atual != NULL && strcmp(no_atual->nome_arquivo, chave) != 0)
        no_atual[i]= no_atual[i+1];

    if (no_atual != NULL)
    {
        if (menu == 3){
            //printar_arquivo(memoria, no_atual);
            printf("achei o arquivo");
        }
        if (menu == 2)
        {
            printf("\nArquivo encontrado pra remoção...");
            /*remove_arquivo->ant = no_anterior;
            remove_arquivo->atual = no_atual;
            return remove_arquivo;*/
        }
    }
    else
    {
        printf("O arquivo não está aqui :(\nQue tal procurar por outro?\n");
        sleep(4);
    }
}

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
