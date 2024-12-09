//
// Created by eteixeira on 09/12/2024.
//

#ifndef ENVIAEMAIL_H
#define ENVIAEMAIL_H

#include <stdio.h>
#include <stdlib.h>


char* lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *conteudo = (char *)malloc((tamanho + 1) * sizeof(char));
    if (conteudo == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    fread(conteudo, sizeof(char), tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo);
    return conteudo;
}

void enviaEmail(const char *destinatario, const char *assunto) {
    const char *nomeArquivo = "email.txt";
    char *conteudo = lerArquivo(nomeArquivo);

    if (conteudo == NULL) {
        printf("Erro ao ler o arquivo. Não foi possível enviar o e-mail.\n");
        return;
    }

    char comando[2048];
    snprintf(comando, sizeof(comando),
             "curl --url 'smtp://smtp.gmail.com:587' "
             "--ssl-reqd "
             "--mail-from 'desenvolvimentostestes@gmail.com' "
             "--mail-rcpt '%s' "
             "--user 'desenvolvimentostestes@gmail.com:senha' "
             "--header 'Subject: %s' "
             "--upload-file %s",
             destinatario, assunto, nomeArquivo);

    int resultado = system(comando);
    if (resultado == 0) {
        printf("E-mail enviado com sucesso!\n");
    } else {
        printf("Erro ao enviar e-mail. Código de retorno: %d\n", resultado);
    }

    free(conteudo);
}


void escreveNoArquivo(const char *conteudo) {
    const char *nomeArquivo = "email.txt";
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fprintf(arquivo, "%s\n", conteudo);
    fclose(arquivo);
    printf("Conteúdo escrito com sucesso no arquivo %s!\n", nomeArquivo);
}

void apagarArquivo() {
    const char *nomeArquivo = "email.txt";
    if (remove(nomeArquivo) == 0) {
        printf("Arquivo %s apagado com sucesso!\n", nomeArquivo);
    } else {
        perror("Erro ao apagar o arquivo");
    }
}



#endif //ENVIAEMAIL_H
