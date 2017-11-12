all: parse.o
	gcc parse.o

parse.o: parse.c
	gcc -c parse.c

clean:
	rm -f *~ *.o a.out

run: all
	./a.out
