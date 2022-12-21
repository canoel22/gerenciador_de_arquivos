#include <stdio.h>
#include "./src/lista/lista.h"
#include "./src/menu/menu.h"


int main()
{
    Lista* lista_encadeada = (Lista *)malloc(sizeof(Lista)); //aloca a cabeça e o retaguarda
    lista_encadeada -> cab = NULL;
    lista_encadeada -> ret = NULL;
    lista_encadeada -> tam = 0;

    while (1)
    {
        tela_inicial(lista_encadeada);  //leva ao menu
    }
    return 0;
}
