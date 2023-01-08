#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../lista/lista.h"

/********************************* Menu ***********************************************/

int tela_inicial(Fita** memoria, int *blocos_ocupados, Arquivos** lista)
{
    int menu = 1;
    while (menu != 6)
    {
        system("clear");
        printf("Bem vindo ao sistema gerenciador de arquivos de texto!\n");
        printf("\n(1) Inserir elemento\n(2) Remover elemento\n(3) Buscar elemento\n(4) Imprimir memória\n(5) Imprimir lista de arquivos\n(6) Sair\n\nDigite a opção que deseja: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:    
            inserir(memoria, blocos_ocupados, lista, menu);
            break;

        case 2:
            remover(memoria, lista, menu, blocos_ocupados);
            break;

        case 3:
            buscar(memoria, lista, menu);
            break;

        case 4:
            printar_fita(memoria);
            break;        
        
        case 5:
            printar_lista(lista);
            break;


        default:
            system("clear");
            exit(0);
            break;
        }
        return 0;
        
    }
}