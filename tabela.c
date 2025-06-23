#include "tabela.h"
void gera_saida(struct tabela *tabela1, struct tabela *tabela2) {
    struct saida vetor[22];  
    int qtd = 0;

    for (int i = 0; i < 11; i++) {
        if (tabela1[i].vazio == 0) {  //aqui adiciona valores de t1 pra saida
            vetor[qtd].chave = tabela1[i].chave;
            vetor[qtd].posicao = i;
            vetor[qtd].tabela[0] = 'T';
            vetor[qtd].tabela[1] = '1';
            vetor[qtd].tabela[2] = '\0';
            qtd++;
        }
    }

    for (int i = 0; i < 11; i++) {
        if (tabela2[i].vazio == 0) { //aqui adiciona valores de t2 pra saida
            vetor[qtd].chave = tabela2[i].chave;
            vetor[qtd].posicao = i;
            vetor[qtd].tabela[0] = 'T';
            vetor[qtd].tabela[1] = '2';
            vetor[qtd].tabela[2] = '\0';
            qtd++;
        }
    }

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) { //ordenacao
            if (vetor[i].chave > vetor[j].chave ||
               (vetor[i].chave == vetor[j].chave && vetor[i].tabela[1] > vetor[j].tabela[1]) ||
               (vetor[i].chave == vetor[j].chave && vetor[i].tabela[1] == vetor[j].tabela[1] && vetor[i].posicao > vetor[j].posicao)) {
                struct saida temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtd; i++) { //formatacao de saida
        printf("%d,%s,%d\n", vetor[i].chave, vetor[i].tabela, vetor[i].posicao);
    }
}

struct tabela *cria_tabela() {
    struct tabela *t = malloc(sizeof(struct tabela) * 11);
    if (!t) {
        printf("Erro ao alocar tabela.\n");
        exit(1);
    }
    for (int i = 0; i < 11; i++) {
        t[i].vazio = 1;
        t[i].excluido = 0;
        t[i].chave = -1;
    }
    return t;
}

//---------------------------------------------------------------
//Calcula h2:
int calcular_h2(int chave) {
    double p = chave * 0.9;
    double parte_decimal = p - (int)p;
    return (int)(11 * parte_decimal);
}

//---------------------------------------------------------------
//Printa tabelas:
void funcao_printa_tabelas(struct tabela *tabela1, struct tabela *tabela2) {
    printf("\n----------------- TABELA 1 -----------------\n");
    printf("| POSIÇÃO | CHAVE |\n");
    printf("--------------------------\n");
    for (int i = 0; i < 11; i++) {
        printf("| %7d | %5d |\n", i, tabela1[i].chave);
    }
    printf("--------------------------\n");
    printf("\n----------------- TABELA 2 -----------------\n");
    printf("| POSIÇÃO | CHAVE |\n");
    printf("--------------------------\n");
    for (int i = 0; i < 11; i++) {
        printf("| %7d | %5d |\n", i, tabela2[i].chave);
    }
    printf("--------------------------\n");
}

//---------------------------------------------------------------
//Exclusão:
void exclusao_tabela(int chave, struct tabela *tabela1, struct tabela *tabela2) {
    int h1 = chave % 11;
    int h2 = calcular_h2(chave);

    if (tabela2[h2].chave == chave && tabela2[h2].vazio == 0) {
        tabela2[h2].chave = -1;
        tabela2[h2].vazio = 1;
    } else if (tabela1[h1].chave == chave && tabela1[h1].vazio == 0) {
        tabela1[h1].chave = -1;
        tabela1[h1].excluido = 1;
        tabela1[h1].vazio = 1;
    }
}