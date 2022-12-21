#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../lista/lista.h"

/********************************* Menu ***********************************************/

int tela_inicial(Lista *lista_encadeada)
{

    int menu = 1;
    while (menu != 5)
    {
        system("clear");
        printf("Bem vindo ao sistema gerenciador de arquivos de texto!\n");
        printf("\n(1) Inserir elemento\n(2) Remover elemento\n(3) Buscar elemento\n(4) Imprimir lista\n(5) Sair\n\nDigite a opção que deseja: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:    
            inserir(lista_encadeada);
            break;

        case 2:
            remover(lista_encadeada, menu);
            break;

        case 3:
            buscar(lista_encadeada, menu);
            break;

        case 4:
            printar(lista_encadeada);
            break;


        default:
            system("clear");
            exit(0);
            break;
        }
        return 0;
        
    }
}