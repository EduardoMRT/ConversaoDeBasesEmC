//
// Created by eteixeira on 05/12/2024.
//

#ifndef CONVERTEPARABINARIO_H
#define CONVERTEPARABINARIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int isValidOctal(const char *octal) {
    for (int i = 0; octal[i] != '\0'; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            return 0;
        }
    }
    return 1;
}

int isValidHexadecimal(const char *hex) {
    for (int i = 0; hex[i] != '\0'; i++) {
        char ch = hex[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))) {
            return 0;
        }
    }
    return 1;
}

char* decimalParaBinario(int decimal) {
    char* binario = (char*) malloc(33); // 32 bits + 1 para o terminador '\0'
    int i = 0;

    if (decimal == 0) {
        binario[i++] = '0';
    } else {
        while (decimal > 0) {
            binario[i++] = (decimal % 2) + '0';
            decimal /= 2;
        }
    }

    binario[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = binario[j];
        binario[j] = binario[i - j - 1];
        binario[i - j - 1] = temp;
    }

    return binario;
}

char* octalParaBinario(const char *octal) {
    if (!isValidOctal(octal)) {
        return NULL;
    }

    int decimal = 0, base = 1, len = strlen(octal);

    for (int i = len - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    return decimalParaBinario(decimal);
}

char* hexadecimalParaBinario(const char *hex) {
    if (!isValidHexadecimal(hex)) {
        return NULL;
    }

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

#endif //CONVERTEPARABINARIO_H
