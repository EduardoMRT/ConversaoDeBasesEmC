//
// Created by eteixeira on 04/11/2024.
//

#ifndef MENU_H
#define MENU_H
#include "utilitarios.h"
#include "../logger/logger.h"

#include<stdio.h>
#include "../structs/pessoa.h"

int menu(const int comecarEm, const int irAte) {
    int opc = 0;

    char menu[10][20] = {"Decimal", "Binario", "Octal", "Hexadecimal", "Ajuda", "Sair"};
    int count = 1;

    for(int i = comecarEm; i <= irAte; i++) {
        printf("\n \t(%d) %s", count, menu[i]);
        count++;
    }

    printf("\n");

    scanf("%d", &opc);
    return opc;
}

void perguntaCadastro(void) {
    int opcEscolhida;
    printf("Deseja cadastrar as suas informações?\n");
    printf("\t (1) SIM \n \t (2) NÃO \n \t (3) O que faremos com elas?\n");
    scanf("%d",&opcEscolhida);
    if(opcEscolhida == 1) {

        FILE *fp = fopen("../arquivos/dadosPessoa.txt", "r");
        if(fp == NULL) {
            printf("\n Não foi possível abrir o arquivo para salvar os dados");
        }

        if(getc(fp) != EOF) {
            printf("\nInformações já cadastradas: ");

            char c = getc(fp);
            while(c != EOF) {
                printf("%c", c);
                c = getc(fp);
            }

            int opc;
            printf("\nDeseja recadastrar? \n\t (1)SIM \n\t (2)NÃO\n");
            scanf("%d", &opc);

            if(opc == 2) {
                return;
            }else if(opc != 1 && opc != 2) {
                _logger(1, "Opção inválida!");
                printf("Erro: Opção inválida! O erro foi adicionado no arquivo de log");
                return;
            }
        }

        Pessoa pessoa;
        limpaTela();
        printf("\nDigite o seu nome: ");
        scanf("%s", &pessoa.nome);
        printf("\nDigite o seu email: ");
        scanf("%s", &pessoa.email);

        FILE *arquivo = fopen("../arquivos/dadosPessoa.txt", "w");
        if(arquivo != NULL) {
            fprintf(arquivo, "%s", pessoa.nome);
            fprintf(arquivo,"\n%s", pessoa.email);
            fclose(arquivo);
        }else {
            perror("Ocorreu um erro ao tentar inserir as informações no arquivo de dados da pessoa");
        }
    }else if(opcEscolhida == 2) {
        return;
    }else if(opcEscolhida == 3) {
        limpaTela();
        FILE *fp = fopen("../arquivos/helpEnvioDeEmails.txt", "r");
        if(fp == NULL) {
            printf("\n Não foi possível abrir o arquivo");
        }else {
            if(getc(fp) != EOF) {
                char c = getc(fp);
                while(c != EOF) {
                    printf("%c", c);
                    c = getc(fp);
                }
            }
        }
        printf("\n");
        perguntaCadastro();
    }
}

#endif //MENU_H
