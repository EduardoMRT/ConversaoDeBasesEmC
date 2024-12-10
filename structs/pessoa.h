//
// Created by eteixeira on 01/11/2024.
//

#ifndef PESSOA_H
#define PESSOA_H

typedef struct{
    char nome[50];
    char email[70];
}Pessoa;

bool verificaDadosPessoaArquivo() {
    FILE *fp;
    if((fp = fopen("../arquivos/dadosPessoa.txt", "a+")) != NULL){
        if (fgetc(fp) == EOF) {
            return false;
        }
        fclose(fp);
        return true;
    }
}

void cadastraPessoa(const char *nome) {
    if(!verificaDadosPessoaArquivo()) {
        FILE *fp;
        if((fp = fopen("../arquivos/dadosPessoa.txt", "a")) != NULL) {
            fputs(nome, fp);
        }
    }
}

char *retornaNomePessoa(void) {
    FILE *fp = fopen("../arquivos/dadosPessoa.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de dados da pessoa");
        return NULL;
    }

    char *nome = malloc(51);
    if (nome == NULL) {
        perror("Erro ao alocar memória");
        fclose(fp);
        return NULL;
    }

    if (fgets(nome, 51, fp) == NULL) {
        perror("Erro ao ler o nome do arquivo");
        free(nome);
        fclose(fp);
        return NULL;
    }

    nome[strcspn(nome, "\n")] = '\0';
    fclose(fp);
    return nome;
}

char *retornaEmailPessoa(void) {
    FILE *fp = fopen("../arquivos/dadosPessoa.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de dados da pessoa");
        return NULL;
    }

    char linha[51];
    if (fgets(linha, sizeof(linha), fp) == NULL) {
        perror("Erro ao ignorar o nome no arquivo");
        fclose(fp);
        return NULL;
    }

    char *email = malloc(71);
    if (email == NULL) {
        perror("Erro ao alocar memória");
        fclose(fp);
        return NULL;
    }

    if (fgets(email, 71, fp) == NULL) {
        perror("Erro ao ler o email do arquivo");
        free(email);
        fclose(fp);
        return NULL;
    }

    email[strcspn(email, "\n")] = '\0';
    fclose(fp);
    return email;
}


#endif //PESSOA_H

