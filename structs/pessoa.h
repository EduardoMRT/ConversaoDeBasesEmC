//
// Created by eteixeira on 01/11/2024.
//

#ifndef PESSOA_H
#define PESSOA_H

#endif //PESSOA_H

typedef struct{
    char nome[50];
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
