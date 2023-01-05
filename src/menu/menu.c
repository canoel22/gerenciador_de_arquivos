#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../lista/lista.h"

/********************************* Menu ***********************************************/

int tela_inicial(Fita *memoria)
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
            inserir(memoria);
            break;

        case 2:
            remover(memoria, menu);
            break;

        case 3:
            buscar(memoria, menu);
            break;

        case 4:
            printar(memoria);
            break;


        default:
            system("clear");
            exit(0);
            break;
        }
        return 0;
        
    }
}