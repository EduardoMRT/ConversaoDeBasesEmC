//
// Created by eteixeira on 04/11/2024.
//

#ifndef MEDIADOR_H
#define MEDIADOR_H

#endif //MEDIADOR_H

#include<stdio.h>
#include "converteParaBinario.h"
#include "converteBinParaBase.h"

bool permitido(char c, const char *permitidos);
bool permissoes(const int opcMenu, char *valor);
bool garanteQueNaoSejaAMesmaOpcao(const int opcMenu, const int opcConverte);
bool gerenciaConversao(int opcMenu, int opcConverte, char* valor);

char permissoesHexadecimal[17] = {'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
char permissoesBinario[2] = {'0', '1'};
char permissoesOctal;
char permissoesDecimal[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void recebeValor(int opcMenu){

    char valor[255];
    char tipo[30];

    getchar();
    printf("\nDigite o valor que deseja converter: ");
    scanf("%254[^\n]", valor);

    printf("\nConverter para: ");
    const int opcConverte = menu(0, 3);


    if(garanteQueNaoSejaAMesmaOpcao(opcMenu, opcConverte)) {
        if(permissoes(opcMenu, valor)) {
            printf("\nConversão permitida");
            gerenciaConversao(opcMenu, opcConverte, valor);
        }else {
            printf("\n Conversão não permitida! O valor digitado não pertence a base");
            _logger(1, "O valor digitado não pertence a base");
            exit(EXIT_FAILURE);
        }
    }else {
        printf("\nVocê não pode converter para a mesma base!");
        exit(EXIT_FAILURE);
    }

}

bool gerenciaConversao(int opcMenu, int opcConverte, char* valor) {
    if(opcMenu == 1) {
        int binario = 0;
        if(opcConverte == 2) {
            binario = decimalParaBinario(atoi(valor));
        }
        if(opcConverte == 3) {
            binario = octalParaBinario(valor);
        }
        if(opcConverte == 4) {
           binario = hexadecimalParaBinario(valor);
        }
        printf("\nValor em binário: %d", binario);
    }
}

bool garanteQueNaoSejaAMesmaOpcao(const int opcMenu, const int opcConverte) {

    if(opcMenu == opcConverte) {
        printf("\nVocê não pode converter para a mesma base");
        recebeValor(opcMenu);
        return false;
    }

    return true;

}

bool permissoes(const int opcMenu, char *valor) {

    if(opcMenu == 1) {
        for (int i = 0; valor[i] != '\0'; i++) {
            if(!permitido(valor[i], permissoesDecimal)) {
                return false;
            }
        }
        return true;
    }

    if(opcMenu == 2) {
        for (int i = 0; valor[i] != '\0'; i++) {
            if(!permitido(valor[i], permissoesBinario)) {
                return false;
            }
        }
        return true;
    }

    if(opcMenu == 3) {
        for (int i = 0; valor[i] != '\0'; i++) {
            if(!permitido(valor[i], permissoesOctal)) {
                return false;
            }
        }
        return true;
    }

    if(opcMenu == 4) {
        for (int i = 0; valor[i] != '\0'; i++) {
            if(!permitido(valor[i], permissoesHexadecimal)) {
                return false;
            }
        }
        return true;
    }
}

bool permitido(char c, const char *permitidos) {
    for (int i = 0; permitidos[i] != '\0'; i++) {
        if (c == permitidos[i]) {
            return true;
        }
    }
    return false;
}


