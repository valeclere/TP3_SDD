CC = gcc
flags = -Wall -Wextra -pedantic



exe : main.o
	${CC} main.o -o exe ${flags}
	echo "executer avec ./exe"
	
main.o : main.c main.h
	${CC} main.c -g -c ${flags}

clean :
	rm *.o exe
