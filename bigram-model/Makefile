CC=clang

CFLAGS=-Wall -Wextra -O2

SRC = bigram.o dict.o line_count.o print_arr.o itos.o stoi.o sample.o random.o prob_dist.o sum_arr.o

bigram: $(SRC) 
	$(CC) $(CFLAGS) -o bigram $(SRC) -lm


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
