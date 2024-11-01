#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs/pessoa.h"

//Inicio de funções
void idioma(void);
void inicio(void);


int main(void) {

    idioma();
    inicio();

    return 0;
}

void idioma(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001");
}

void inicio(void) {

    Pessoa pessoa;

    bool cadastraPessoa = verificaDadosPessoaArquivo();
    printf("%hhd", cadastraPessoa);


    printf("\nSISTEMA DE CONVERSÃO DE BASES");
}