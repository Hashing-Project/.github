#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//---------------------------------------------------------------
//Função que cria tabela:
struct tabela *cria_tabela() {
	struct tabela *t = malloc(sizeof(struct tabela)*11);

	if (!t) {
		printf("erro ao alocar memória para criar tabela.\n");
		return NULL;
	}

//inicializando todos a tabela como vazia em todas as suas posições:
	for (int i=0 ; i<11 ; i++)
		t[i].vazio = 1;

	return t;
}
//---------------------------------------------------------------
//Função que faz a função h2:
int funcao_h2(int h1, struct tabela *tabela1, int input2) {
	//salvando a chave que vai ir para a tabela 2:
	int temporario = tabela1[h1].chave;
	//substituindo o valor na tabela1 pela nova chave:
	tabela1[h1].chave = input2;
	double p1 = temporario*0.9;
	double p2 = p1 - (int)p1;
	int h2 = (int)(11*p2);
	return h2;
}
//---------------------------------------------------------------
//Função que printa tabelas:
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
//Função main:
int main() {

	struct tabela *tabela1 = cria_tabela();
	struct tabela *tabela2 = cria_tabela();

	char input1;
	int input2;
	int controle = 1;
	while(controle) {
		scanf(" %c %d", &input1, &input2);
		if (input1 == 'i') {
			int h1 = input2 % 11;
			//se está vazio:
			if (tabela1[h1].vazio == 1) {
				tabela1[h1].chave = input2;
				tabela1[h1].vazio = 0;
			}
			//se a posição já estiver sendo ocupada na tabela1:
			else {
				//salvando a chave que vai ir para a tabela 2:
				int temporario = tabela1[h1].chave;
				//chamando função h2:
				int h2 = funcao_h2(h1, tabela1, input2);
				tabela2[h2].chave = temporario;
				tabela2[h2].vazio = 0;
			}
		}
		else
			controle = 0;
	}

	funcao_printa_tabelas(tabela1, tabela2);
	return 0;
}
