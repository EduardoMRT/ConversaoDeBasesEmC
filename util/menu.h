//
// Created by eteixeira on 04/11/2024.
//

#ifndef MENU_H
#define MENU_H

#endif //MENU_H
#include<stdio.h>

inline int menu(int comecarEm, int irAte) {
    int opc = 0;

    char menu[10][20] = {'Decimal', 'Binario', 'Octal', 'Hexadecimal', 'Ajuda', 'Sair'};
    int count = 1;

    for(int i = comecarEm; i <= irAte; i++) {
        printf("\n (%d) %s", count, menu[i]);
        count++;
    }

    scanf("%d", &opc);
    return opc;
}