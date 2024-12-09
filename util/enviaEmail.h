//
// Created by eteixeira on 09/12/2024.
//

#ifndef ENVIAEMAIL_H
#define ENVIAEMAIL_H

#include <stdio.h>
#include <stdlib.h>

void envia_email(const char *email_destinatario, const char *assunto, const char *mensagem) {
    // Cria um arquivo temporário para armazenar o conteúdo do e-mail
    FILE *temp_file = fopen("temp_email.txt", "w");
    if (temp_file == NULL) {
        perror("Erro ao criar arquivo temporário");
        return;
    }

    fprintf(temp_file, "From: desenvolvimentostestes@gmail.com\n");
    fprintf(temp_file, "To: %s\n", email_destinatario);
    fprintf(temp_file, "Subject: %s\n", assunto);
    fprintf(temp_file, "\n");
    fprintf(temp_file, "%s\n", mensagem);
    fclose(temp_file);

    char cmd[2048];
    snprintf(cmd, sizeof(cmd),
        "curl --url \"smtp://smtp.gmail.com:587\" "
        "--ssl-reqd "
        "--mail-from \"desenvolvimentostestes@gmail.com\" "
        "--mail-rcpt \"%s\" "
        "--user \"desenvolvimentostestes@gmail.com:dgvtcyiyjwiwsykz\" "
        "--upload-file temp_email.txt",
        email_destinatario);

    printf("Comando curl gerado:\n%s\n", cmd);

    int ret = system(cmd);

    if (ret == 0) {
        printf("E-mail enviado com sucesso.\n");
    } else {
        printf("Erro ao enviar e-mail. Código de retorno: %d\n", ret);
    }

    remove("temp_email.txt");
}


#endif //ENVIAEMAIL_H
