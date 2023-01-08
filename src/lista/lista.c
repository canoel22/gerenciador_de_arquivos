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

void limpar_lista(Arquivos **lista)
{
    for (int i = 0; i < TAM_BLOCO; i++)
    {
        lista[i] = NULL;
    }
}

/********************************* Inserir ***********************************************/
void inserir(Fita** memoria, int *blocos_ocupados, Arquivos **lista, int menu) {

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
                remover(memoria, lista, menu, blocos_ocupados);
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

    for (int k=0; k<TAM_MEMORIA; k++){
        if (lista[k] == NULL){
            Arquivos *novo_arquivo = (Arquivos*)malloc(sizeof(Arquivos));
            strcpy(novo_arquivo-> nome_arquivo, nome_arquivo);
            novo_arquivo -> qtd_blocos = cont;
            novo_arquivo -> indice_inicial = arquivo_indice1;
            break;
        }
    }

    printf("Aquivo inserido perfeitamente! :)\n");
    printf("%d/100 da memória ocupada", *blocos_ocupados);

    printar_lista(lista);
    
    sleep(3);
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

void remover(Fita **memoria, Arquivos **lista, int menu, int *blocos_ocupados)
{
    Arquivos *inicio = (buscar(memoria, lista, menu));
    
    if (inicio== NULL){
        return;
    }

    int i = inicio -> indice_inicial;
    char* nome = inicio -> nome_arquivo;
    int tam = inicio -> qtd_blocos;

    Fita aux = *memoria[i];

    for(int j = 0; j < tam; j++){
        memoria[i] = NULL;
        i = memoria[i]->indice_prox;
        free(memoria[i]);
        aux = *memoria[i];
        *blocos_ocupados -= 1;

    }

    inicio = NULL;
    free(inicio);
    printf("Arquivo removido perfeitamente! :)\n");
    sleep(3);
    return;
}

/********************************* Buscar ***********************************************/

Arquivos *buscar(Fita **memoria, Arquivos **lista, int menu)
{
    char chave[50];
    int i = 0;
    Arquivos *no_atual; 

    system("clear");

    printf("Digite o nome arquivo: ");
    scanf("%s", chave);

    for (i=0; i<TAM_MEMORIA; i++){
        no_atual = lista[i];
        if (no_atual != NULL && strcmp(chave, no_atual->nome_arquivo) == 0){
            if (menu == 2){
                printf("\nArquivo encontrado...\n");
                sleep(3);
                return no_atual;
            }else{
                printf("oi");
                //printar_arquivo(memoria, no_atual);
                break;
            }
        }

    } 

    printf("O arquivo não está aqui... Que tal adicioná-lo através da opção (1) do menu?\n");
    sleep(3);
    return NULL;

}

/***************************** Imprimir listas pra teste ******************************************/

void printar_fita(Fita **memoria)
{
    system("clear");
    int i =0;
    Fita *no_atual;

    for (i=0; i<TAM_MEMORIA; i++){
        no_atual = memoria[i];
        if (no_atual != NULL){
            printf("-> Nó %d\nNome do arquivo: %s\nEndereço: %p\n", i, no_atual->nome_arquivo, no_atual);
            printf("Conteúdo do arquivo: %s\n\n", no_atual->arquivo);
        }
    }
    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();

} 
void printar_lista(Arquivos **lista){
    //system("clear");
    int i =0;
    Arquivos *no_atual;

    for (i=0; i<TAM_MEMORIA; i++){
        no_atual = lista[i];
        if (no_atual != NULL){
            printf("-> Nó %d\nNome do arquivo: %s\nQtd de blocos: %d\n", i, no_atual->nome_arquivo, no_atual->qtd_blocos);
            printf("Índice inicial: %d\n\n", no_atual->indice_inicial);
        }
    }
    printf("\n\nDigite enter para sair.");
    scanf("%*c");
    getchar();
}

/******************************* Imprimir arquivo *********************************************/

void printar_arquivo(Fita **memoria, Fita *no_atual)
{
   /*system("clear");
    printf("Achei! O arquivo está aqui:\n");
    No *cab = memoria->cab;
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
