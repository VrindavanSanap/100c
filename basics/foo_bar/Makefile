all: bar

bar: bar.o foo.o
	clang bar.o foo.o -o bar

bar.o: bar.c
	clang -c bar.c -o bar.o

foo.o: foo.c
	clang -c foo.c -o foo.o

clean:
	rm -f *.o foo bar
