//
// Created by eteixeira on 05/12/2024.
//

#ifndef CONVERTEBINPARABASE_H
#define CONVERTEBINPARABASE_H

#endif //CONVERTEBINPARABASE_H

#include <stdio.h>
#include <string.h>
#include <math.h>

int binarioParaDecimal(const char *bin) {
    int decimal = 0, len = strlen(bin);

    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            decimal += pow(2, len - 1 - i);
        }
    }
    return decimal;
}

void binarioParaOctal(const char *bin) {
    int decimal = binarioParaDecimal(bin);
    char octal[100];
    int i = 0;

    while (decimal != 0) {
        octal[i++] = (decimal % 8) + '0';
        decimal /= 8;
    }
    octal[i] = '\0';

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", octal[j]);
    }
}

void binarioParaHexadecimal(const char *bin) {
    int decimal = binarioParaDecimal(bin);
    char hex[100];
    int i = 0;

    while (decimal != 0) {
        int temp = decimal % 16;
        if (temp < 10) {
            hex[i++] = temp + '0';
        } else {
            hex[i++] = temp - 10 + 'A';
        }
        decimal /= 16;
    }
    hex[i] = '\0';

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}