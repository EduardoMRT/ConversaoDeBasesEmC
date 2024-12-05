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

int decimalParaBinario(int decimal) {
    int binario = 0, pos = 1;

    while (decimal != 0) {
        binario += (decimal % 2) * pos;
        decimal /= 2;
        pos *= 10;
    }

    return binario;
}

int octalParaBinario(const char *octal) {
    int decimal = 0, base = 1, len = strlen(octal);

    for (int i = len - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    return decimalParaBinario(decimal);
}

int hexadecimalParaBinario(const char *hex) {
    int decimal = 0, base = 1, len = strlen(hex);

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

    return decimalParaBinario(decimal);
}