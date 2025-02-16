CC=clang

CFLAGS=-Wall -Wextra -O2

OBJS = bigram.o dict.o line_count.o itos.o stoi.o sample.o random.o prob_dist.o sum_arr.o

TARGET = bigram
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm
  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

