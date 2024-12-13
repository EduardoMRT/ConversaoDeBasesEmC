//
// Created by eteixeira on 04/11/2024.
//

#ifndef MEDIADOR_H
#define MEDIADOR_H

#include<stdio.h>
#include "converteParaBinario.h"
#include "converteBinParaBase.h"
#include "enviaEmail.h"
#include "utilitarios.h"

bool permitido(char c, const char *permitidos);
bool permissoes(const int opcMenu, char *valor);
bool garanteQueNaoSejaAMesmaOpcao(const int opcMenu, const int opcConverte);
bool gerenciaConversao(int opcMenu, int opcConverte, char* valor);
void chamaEmail(const char* valor, const char* valorConvertido, const char* baseEnvio, const char* baseSaida);

char permissoesHexadecimal[17] = {'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
char permissoesBinario[2] = {'0', '1'};
char permissoesOctal[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
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

     if(opcConverte == 1) {
        int decimal;
        char decimalConvertido[128];
        char baseEnvio[20];
        char baseSaida[20];

         strcat(baseSaida, " (Decimal) ");

        if(opcMenu == 2) {
            printf("\nValor em decimal: %d", binarioParaDecimal(valor));
            strcat(baseEnvio, " (Binario) ");
        }
        else if(opcMenu == 3) {
            decimal = octalParaBinario(valor);
            sprintf(decimalConvertido, "%d", decimal);
            printf("\nValor em decimal: %s", binarioParaOctal(decimalConvertido));
            strcat(baseEnvio, " (Octal) ");
        }
        else if(opcMenu == 4) {
            decimal = hexadecimalParaBinario(valor);
            sprintf(decimalConvertido, "%d", decimal);
            printf("\nValor em decimal: %s", binarioParaHexadecimal(decimalConvertido));
            strcat(baseEnvio, " (Hexadecimal) ");
        }
         chamaEmail(valor, decimalConvertido, baseEnvio, baseSaida);
    }

    else if(opcConverte == 2) {
        int binario = 0;
        char baseEnvio[20];
        char baseSaida[20];

        strcat(baseSaida, " (Binario) ");


        if(opcMenu == 1) {
            binario = decimalParaBinario(atoi(valor));
            strcat(baseEnvio, " (Decimal) ");
        }
        else if(opcMenu == 3) {
            binario = octalParaBinario(valor);
            strcat(baseEnvio, " (Octal) ");
        }
        else if(opcMenu == 4) {
           binario = hexadecimalParaBinario(valor);
            strcat(baseEnvio, " (Hexadecimal) ");
        }
        printf("\nValor em binário: %d", binario);
        char binarioConvertido[128], mensagem[248];
        sprintf(binarioConvertido, "%d", binario);
        chamaEmail(valor, binarioConvertido, baseEnvio, baseSaida);
    }

    else if(opcConverte == 3) {
        char binarioConvertido[128];
        char octalConvertido[128];
        int binario;
        char baseEnvio[20];
        char baseSaida[20];

        strcat(baseSaida, " (Octal) ");
        if(opcMenu == 1) {
            binario = decimalParaBinario(atoi(valor));
            sprintf(binarioConvertido, "%d", binario);
            printf("\nValor em octal: %s", binarioParaOctal(binarioConvertido));
            strcat(octalConvertido, binarioParaOctal(binarioConvertido));
            strcat(baseEnvio, " (Decimal) ");
        }
        else if(opcMenu == 2) {
            printf("\nValor em octal: %s", binarioParaOctal(valor));
            strcat(octalConvertido, binarioParaOctal(valor));
            strcat(baseEnvio, " (Binario) ");
        }
        else if(opcMenu == 4) {
            binario = hexadecimalParaBinario(valor);
            sprintf(binarioConvertido, "%d", binario);
            printf("\nValor em octal: %s", binarioParaOctal(binarioConvertido));
            strcat(octalConvertido, binarioParaOctal(binarioConvertido));
            strcat(baseEnvio, " (Hexadecimal) ");
        }
        chamaEmail(valor, octalConvertido, baseEnvio, baseSaida);
    }

    else if(opcConverte == 4) {
        char binarioConvertido[128];
        int binario;
        char hexadecimalConvertido[128];
        char baseEnvio[20];
        char baseSaida[20];

        strcat(baseSaida, " (Hexadecimal) ");
        if(opcMenu == 1) {
            binario = decimalParaBinario(atoi(valor));
            sprintf(binarioConvertido, "%d", binario);
            printf("\nValor em Hexadecimal: %s", binarioParaHexadecimal(binarioConvertido));
            strcat(hexadecimalConvertido, binarioParaHexadecimal(binarioConvertido));
            strcat(baseEnvio, " (Decimal) ");
        }
        else if(opcMenu == 2) {
            printf("\nValor em Hexadecimal: %s", binarioParaHexadecimal(valor));
            strcat(hexadecimalConvertido, binarioParaHexadecimal(valor));
            strcat(baseEnvio, " (Binario) ");
        }
        else if(opcMenu == 3) {
            binario = octalParaBinario(valor);
            sprintf(binarioConvertido, "%d", binario);
            printf("\nValor em Hexadecimal: %s", binarioParaHexadecimal(valor));
            strcat(hexadecimalConvertido, binarioParaHexadecimal(valor));
            strcat(baseEnvio, " (Octal) ");
        }
        chamaEmail(valor, hexadecimalConvertido, baseEnvio, baseSaida);
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

void chamaEmail(const char* valor, const char* valorConvertido, const char* baseEnvio, const char* baseSaida) {
    int opc;
    printf("\nDeseja enviar o resultado no seu e-mail? \n\t(1)SIM \n\t(2)NÃO\n");
    scanf("%d", &opc);

    if(opc == 1) {
        char mensagem[500];
        memset(mensagem, '\0', 499);
        strcat(mensagem, "Prezado(a) sr(a).");
        strcat(mensagem, retornaNomePessoa());
        strcat(mensagem, ", com muito prazer lhe informo o resultado de suas conversoes: \n");
        strcat(mensagem, baseEnvio);
        strcat(mensagem, valor);
        strcat(mensagem, " convertido para: ");
        strcat(mensagem, baseSaida);
        strcat(mensagem, valorConvertido);
        strcat(mensagem, "\n\n\nDesenvolvido por: Eduardo M.R. Teixeira");
        removeCaracteresEspeciais(mensagem);

        envia_email(retornaEmailPessoa(), "Conversão de Bases em C", mensagem);
    }else {
        return;
    }

}

#endif //MEDIADOR_H
