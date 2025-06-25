#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"


int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printf("Nome: Matheus Gastal Magalhães\n");
        printf("GRR: GRR20244620\n");
        printf("login: mgm24\n");
        printf("Nome: Antonio da Ressurreição Filho\n");
        printf("GRR: GRR20245202\n");
        printf("login: arf24\n");
        return 0;
    }
    struct tabela *tabela1 = cria_tabela();
    struct tabela *tabela2 = cria_tabela();

    int chave;
	char input1;
    while(scanf(" %c %d", &input1, &chave) == 2) {
        if(input1 == 'i') {
            int h1 = chave % 11;

            if (tabela1[h1].vazio == 1 || tabela1[h1].excluido == 1) {
                tabela1[h1].chave = chave;
                tabela1[h1].vazio = 0;
                tabela1[h1].excluido = 0;
            }
            else {
                int antiga = tabela1[h1].chave;
                int h2_antiga = calcular_h2(antiga);

                tabela2[h2_antiga].chave = antiga;
                tabela2[h2_antiga].vazio = 0;

                tabela1[h1].chave = chave;
                tabela1[h1].vazio = 0;
                tabela1[h1].excluido = 0;
            }
        }

        else if(input1 == 'r') {
            exclusao_tabela(chave, tabela1, tabela2);
        }
        else {
			break;
		}
    }

    gera_saida(tabela1,tabela2);

    free(tabela1);
    free(tabela2);

    return 0;
}
