//
// Created by eteixeira on 05/12/2024.
//

#ifndef CONVERTEBINPARABASE_H
#define CONVERTEBINPARABASE_H

#include <stdio.h>
#include <string.h>
#include <math.h>

int isValidBinary(const char *bin) {
    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] != '0' && bin[i] != '1') {
            return 0;
        }
    }
    return 1;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int binarioParaDecimal(const char *bin) {
    if (!isValidBinary(bin)) return -1;

    int decimal = 0, len = strlen(bin);

    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            decimal += (1 << (len - 1 - i)); // Bit shift
        }
    }
    return decimal;
}

char* binarioParaOctal(const char *bin) {
    int decimal = binarioParaDecimal(bin);
    if (decimal == -1) return NULL;

    int size = (strlen(bin) / 3) + 2;
    char *octal = (char *)malloc(size * sizeof(char));
    int i = 0;

    if (decimal == 0) {
        octal[i++] = '0';
    } else {
        while (decimal != 0) {
            octal[i++] = (decimal % 8) + '0';
            decimal /= 8;
        }
    }
    octal[i] = '\0';
    reverseString(octal);
    return octal;
}

char* binarioParaHexadecimal(const char *bin) {
    int decimal = binarioParaDecimal(bin);
    if (decimal == -1) return NULL;

    int size = (strlen(bin) / 4) + 2;
    char *hex = (char *)malloc(size * sizeof(char));
    int i = 0;

    if (decimal == 0) {
        hex[i++] = '0';
    } else {
        while (decimal != 0) {
            int temp = decimal % 16;
            hex[i++] = (temp < 10) ? temp + '0' : temp - 10 + 'A';
            decimal /= 16;
        }
    }
    hex[i] = '\0';
    reverseString(hex);
    return hex;
}

#endif //CONVERTEBINPARABASE_H

