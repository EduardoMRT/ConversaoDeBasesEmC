//
// Created by eteixeira on 01/11/2024.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <string.h>
#include <time.h>

#endif //LOGGER_H

typedef struct{
    int nivel_alert;
    char *erro;
} Logger;


void _logger(int nivel_alert, char *erro) {
    Logger logger;
    logger.nivel_alert = nivel_alert;
    logger.erro = erro;

    time_t agora = time(NULL);
    char *dataHoraAtual = ctime(&agora);

    // Remove o caractere de nova linha, se presente
    dataHoraAtual[strcspn(dataHoraAtual, "\n")] = 0;

    char loggerToString[512]; // Ajuste o tamanho conforme necessário
    snprintf(loggerToString, sizeof(loggerToString), "\n%d -> [%s] : %s",
             logger.nivel_alert, dataHoraAtual, logger.erro);

    if (erro == NULL) {
        fprintf(stderr, "Erro: Ponteiro 'erro' e nulo.\n");
    }

    FILE *fp = fopen("../arquivos/log.txt", "a");

    if(fp) {
        fprintf(fp, "%s", loggerToString);
        printf("\nO erro foi adicionado no arquivo de log");
        fclose(fp);
    }else {
        perror("\nNao foi possivel obter acesso ao arquivo de log");
    }
}