#ifndef __menu_h
#define __menu_h

#include <stdio.h>
#include <stdlib.h>
#include "../lista/lista.h"

/// @brief função responsável pelo menu
/// @param memoria é onde o conteúdo/informações dos arquivos estão armazenados
/// @param blocos_ocupados é a quantidade de blocos que estão sendo usados no momento
/// @param lista é onde os dados de cada arquivo estão cadastrados
/// @return retorna 0 para sair do sistema
int tela_inicial(Fita** memoria, int *blocos_ocupados, Arquivos **lista);

#endif