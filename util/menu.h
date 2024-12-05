//
// Created by eteixeira on 04/11/2024.
//

#ifndef MENU_H
#define MENU_H

#endif //MENU_H
#include<stdio.h>

int menu(const int comecarEm, const int irAte) {
    int opc = 0;

    char menu[10][20] = {"Decimal", "Binario", "Octal", "Hexadecimal", "Ajuda", "Sair"};
    int count = 1;

    for(int i = comecarEm; i <= irAte; i++) {
        printf("\n \t(%d) %s", count, menu[i]);
        count++;
    }

    printf("\n");

    scanf("%d", &opc);
    return opc;
}