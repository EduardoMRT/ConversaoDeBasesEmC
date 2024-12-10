//
// Created by eteixeira on 04/11/2024.
//

#ifndef REDIRECIONA_H
#define REDIRECIONA_H

#include "utilitarios.h"
#include "ajuda.h"

int redirecionaPosMenu(int opc){
    for(int i = 1; i <= 6; i++) {
        if(i == opc) {
            if(i == 5) {
                ajuda();
                printf("\nAperte enter para continuar...");
                getchar(); getchar();
                return 2;
            }else if(i == 6) {
                exit(1);
            }
            return 1;
        }
    }
    limpaTela();
    return 0;
}

#endif //REDIRECIONA_H

