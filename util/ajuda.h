//
// Created by eteixeira on 05/12/2024.
//

#ifndef AJUDA_H
#define AJUDA_H
#endif //AJUDA_H


void ajuda(){
    limpaTela();
    FILE *fp = fopen("../arquivos/ajuda.txt", "r");
    if(fp) {
        char c = fgetc(fp);
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(fp);
        }
        fclose(fp);
    }else {
        perror("\nNão foi possível abrir o arquivo de ajuda");
    }


}