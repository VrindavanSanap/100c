all: simple_goto

simple_goto: simple_goto.o
	clang simple_goto.o -o simple_goto
	
simple_goto.o: simple_goto.c
	clang -c simple_goto.c -o simple_goto.o

clean:
	rm -f *.o simple_goto