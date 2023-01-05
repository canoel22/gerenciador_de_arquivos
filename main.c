#include <stdio.h>
#include "./src/lista/lista.h"
#include "./src/menu/menu.h"

Fita *arquivos[TAM_MEMORIA];
Bloco *memoria;

int main()
{
    memoria->ocupado = 0;

    while (1)
    {
        tela_inicial();  //leva ao menu
    }
    return 0;
}
