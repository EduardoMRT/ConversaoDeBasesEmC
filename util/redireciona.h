//
// Created by eteixeira on 04/11/2024.
//

#ifndef REDIRECIONA_H
#define REDIRECIONA_H

#endif //REDIRECIONA_H

#include "decimal.h";
#include "binario.h";
#include "octal.h";
#include "hexadecimal.h";
#include "utilitarios.h";

bool redirecionaPosMenu(int opc){
    if(opc == 1){
        Decimal();
        return true;
    }else if(opc == 2){
        Binario();
        return true;
    }else if(opc == 3){
        Octal();
        return true;
    }else if(opc == 4){
        Hexadecimal();
        return true;
    }else if(opc == 5){
        return true;
    }else if(opc == 6){
        sair();
        return true;
    }
    limpaTela();
    return false;
}