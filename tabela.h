#ifndef tabela_h
#define tabela_h

#include <stdio.h>
#include <stdlib.h>

struct tabela {
	int chave;
	int vazio;
	int excluido;
};

struct saida {
    int chave;
    char tabela[3]; 
    int posicao;
};

void gera_saida(struct tabela *tabela1, struct tabela *tabela2);
struct tabela *cria_tabela();
int calcular_h2(int chave);
void funcao_printa_tabelas(struct tabela *tabela1, struct tabela *tabela2);
void exclusao_tabela(int chave, struct tabela *tabela1, struct tabela *tabela2);
#endif
