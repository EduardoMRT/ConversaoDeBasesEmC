//
// Created by eteixeira on 04/11/2024.
//

#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include<stdlib.h>
#include<stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


void sair(){
    printf("\n Você escolheu sair.");
    exit(0);
}

void removeCaracteresEspeciais(char *string) {
    char *leitura = string;
    char *escrita = string;

    while (*leitura) {
        if (isalnum((unsigned char)*leitura) || *leitura == ' ' || *leitura == ':' || *leitura == '.' ||
            *leitura == '(' || *leitura == ')' || *leitura == '\n') {


            if (*leitura == '0' && (!isdigit((unsigned char)*(leitura - 1)) && !isdigit((unsigned char)*(leitura + 1)))) {
                leitura++;
                continue;
            }

            *escrita = *leitura;
            escrita++;
            }
        leitura++;
    }
    *escrita = '\0';
}

void limpaTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#endif //UTILITARIOS_H

