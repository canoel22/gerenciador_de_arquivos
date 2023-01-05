#include <stdio.h>
#include "./src/lista/lista.h"
#include "./src/menu/menu.h"

#define TAM_MEMORIA 100

Fita memoria[TAM_MEMORIA];

int main()
{
    while (1)
    {
        tela_inicial(memoria);  //leva ao menu
    }
    return 0;
}
