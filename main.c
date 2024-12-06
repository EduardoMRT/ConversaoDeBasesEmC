#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "util/menu.h"
#include "util/redireciona.h"
#include "logger/logger.h"
#include "util/mediador.h"

//Inicio de funções
void idioma(void);
void inicio(void);

int main(void) {
    idioma();
    inicio();

    const int opcMenu = menu(0, 5);

    const int retorno = redirecionaPosMenu(opcMenu);
    if(retorno == 0) {
        _logger(1, "Opção do menu é inválida!");
        main();
    }else if(retorno == 2) {
        limpaTela();
        main();
    }

    recebeValor(opcMenu);

    printf("\nAperte enter para encerrar o programa.");
    getchar(); getchar();
    return 0;
}

void idioma(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001");
}

void inicio(void) {
    printf("\nSISTEMA DE CONVERSÃO DE BASES");
    printf("\nDigite a Base que você irá enviar: ");
}



