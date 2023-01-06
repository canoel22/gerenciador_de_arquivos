#include <stdio.h>
#include "./src/lista/lista.h"
#include "./src/menu/menu.h"


int main()
{
    Fita *memoria[TAM_MEMORIA];
    limpar_memoria(memoria);
    int blocos_ocupados;

    while (1)
    {
        tela_inicial(memoria, blocos_ocupados);  //leva ao menu
    }
    return 0;
}
