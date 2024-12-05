//
// Created by eteixeira on 05/12/2024.
//

#ifndef CONVERTEPARABINARIO_H
#define CONVERTEPARABINARIO_H

#endif //CONVERTEPARABINARIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void decimalParaBinario(int decimal) {
    char binario[100];
    int i = 0;

    while (decimal != 0) {
        binario[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binario[i] = '\0';

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binario[j]);
    }
}

void octalParaBinario(const char *octal) {
    int decimal = 0, base = 1;
    int len = strlen(octal);

    for (int i = len - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    decimalParaBinario(decimal);
}

void hexadecimalParaBinario(const char *hex) {
    int decimal = 0, base = 1;
    int len = strlen(hex);

    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];
        if (ch >= '0' && ch <= '9') {
            decimal += (ch - '0') * base;
        } else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 'A' + 10) * base;
        } else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 'a' + 10) * base;
        }
        base *= 16;
    }

    decimalParaBinario(decimal);
}