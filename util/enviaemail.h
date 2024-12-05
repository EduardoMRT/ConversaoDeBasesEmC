//
// Created by eteixeira on 05/12/2024.
//

#ifndef ENVIAEMAIL_H
#define ENVIAEMAIL_H

#endif ENVIAEMAIL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

int enviaEmail(const char *para, const char *assunto, const char *mensagem) {
    CURL *curl;
    CURLcode res;


    const char *smtp_url = "smtp://smtp.seuservidor.com:587";
    const char *usuario = "Edukstestes@gmail.com";
    const char *senha = "Edukstestes0101";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Erro ao inicializar a libcurl\n");
        return -1;
    }

    struct curl_slist *recipients = NULL;
    char userpwd[256];
    snprintf(userpwd, sizeof(userpwd), "%s:%s", usuario, senha);

    curl_easy_setopt(curl, CURLOPT_URL, smtp_url);
    curl_easy_setopt(curl, CURLOPT_USERNAME, usuario);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, senha);
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, usuario);

    recipients = curl_slist_append(recipients, para);
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    char email_message[1024];
    snprintf(email_message, sizeof(email_message),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s",
             usuario, para, assunto, mensagem);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, email_message);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "Erro ao enviar o e-mail: %s\n", curl_easy_strerror(res));
    } else {
        printf("E-mail enviado com sucesso!\n");
    }

    curl_slist_free_all(recipients);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return (res == CURLE_OK) ? 0 : -1;
}