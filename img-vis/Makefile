# Makefile for compiling and running main.c with SDL2

# Variables
CC = clang
CFLAGS = -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2 -lSDL2_image
SRC = main.c
EXEC = main

# Default target
all: $(EXEC)

# Compile the program
$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS) $(LDFLAGS)

# Run the program
run: $(EXEC)
	./$(EXEC)

# Clean the build
clean:
	rm -f $(EXEC)
