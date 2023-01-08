#include <stdio.h>
#include "./src/lista/lista.h"
#include "./src/menu/menu.h"

int main()
{
    Fita *memoria[TAM_MEMORIA]; // vetor que armazena os conteúdos
    limpar_memoria(memoria);
    int blocos_ocupados = 0;

    Arquivos *lista[TAM_MEMORIA]; // vetor que armazena os dados sobre os arquivos
    limpar_lista(lista);

    while (1)
    {
        tela_inicial(memoria, &blocos_ocupados, lista); // leva ao menu
    }
    return 0;
}
