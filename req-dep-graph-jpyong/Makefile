dGraph: parse.o tree.o
	gcc -Wall -std=c11 parse.o tree.o -o dGraph

parse.o: parse.c parse.h
	gcc parse.c -Wall -std=c11 -c -o parse.o

tree.o: tree.c tree.h
	gcc tree.c -Wall -std=c11 -c -o tree.o

clean: 
	rm -rf *.o dGraph