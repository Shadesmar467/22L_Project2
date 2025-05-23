CFLAGS = -Wall -std=c11 -Iinclude

dGraph: parse.o tree.o main.o
	gcc $(CFLAGS) parse.o tree.o main.o -o dGraph

main.o: src/main.c
	gcc $(CFLAGS) src/main.c -c -o main.o

parse.o: src/parse.c include/parse.h
	gcc $(CFLAGS) src/parse.c -c -o parse.o -lregex

tree.o: src/tree.c include/tree.h
	gcc $(CFLAGS) src/tree.c -c -o tree.o

clean: 
	rm -rf *.o dGraph