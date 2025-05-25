CC = clang
CFLAGS = -Wall -Wextra 
OBJS = main.o tweet.o

TARGET = main
main: main.o tweet.o
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)



$%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
