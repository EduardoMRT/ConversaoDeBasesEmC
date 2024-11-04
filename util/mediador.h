//
// Created by eteixeira on 04/11/2024.
//

#ifndef MEDIADOR_H
#define MEDIADOR_H

#endif //MEDIADOR_H

#include<stdio.h>

inline char* recebeValor(int opcMenu){

    char permissoesHexadecimal[17] = {'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char permissoesBinario[2] = {'0', '1'};
    char permissoesOctal;
    char permissoesDecimal[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char valor[255];
    char tipo[30];

    printf("\nDigite o valor que deseja converter: ");
    scanf("%254[^\n]", valor);
    printf("Converter para: ");

    return "";
}

inline bool garanteQueNaoSejaAMesmaOpcao(const int opcMenu, const int opcConverte) {

    if(opcMenu == opcConverte) {
        printf("\nVocê não pode converter para esse tipo, pois o valor digitado já é");
        limpaTela();
        recebeValor(opcMenu);
        return false;
    }

    return true;

}


