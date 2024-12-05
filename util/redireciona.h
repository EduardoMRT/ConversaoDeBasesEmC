//
// Created by eteixeira on 04/11/2024.
//

#ifndef REDIRECIONA_H
#define REDIRECIONA_H

#endif //REDIRECIONA_H

#include "utilitarios.h";

bool redirecionaPosMenu(int opc){
    for(int i = 1; i <= 6; i++) {
        if(i == opc) {
            return true;
        }
    }
    limpaTela();
    return false;
}