all: read_bin write_bin

read_bin: read_bin.o
	clang read_bin.o -o read_bin
read_bin.o:read_bin.c
	clang -c read_bin.c -o read_bin.o

write_bin: write_bin.o
	clang write_bin.o -o write_bin 
write_bin.o: write_bin.c
	clang -c write_bin.c -o write_bin.o

clean:
	rm -f *.o read_bin write_bin