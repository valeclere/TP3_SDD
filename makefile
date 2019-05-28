CC= gcc
CFLAGS=-Wall -Wextra -pedantic

OBJ= main.o arbre.o dico.o pile.o

EXEC=exec

$(EXEC) : $(OBJ)
	$(CC) -g $^ -o $@
	echo "executer avec ./exec"

%.o : %.c
	$(CC) -g -c $< $(CFLAGS)

clean :
	rm -rf dep *.o vgcore.*
