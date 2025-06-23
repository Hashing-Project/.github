# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Arquivos
OBJ = main.o tabela.o
EXEC = myht

# Regra padrão
all: $(EXEC)

# Regra para gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Compilar main.c
main.o: main.c tabela.h
	$(CC) $(CFLAGS) -c main.c

# Compilar tabela.c
tabela.o: tabela.c tabela.h
	$(CC) $(CFLAGS) -c tabela.c

# Limpar arquivos objeto e executável
clean:
	rm -f *.o $(EXEC)
