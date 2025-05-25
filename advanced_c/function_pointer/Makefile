CC = clang
CFLAGS = -I ../../basics -Wall -Wextra -O2
SRCS = qsort.c
OBJS_QSORT = qsort.o 
OBJS_BSORT = bsort.o 
OBJS = ../../basics/print_arr.o
all: qsort bsort

# Compile print_arr.c into print_arr.o if it doesn't exist
../../basics/print_arr.o: ../../basics/print_arr.c
	$(CC) $(CFLAGS) -c ../../basics/print_arr.c -o ../../basics/print_arr.o


# Compile qsort.c into qsort.o
qsort.o: qsort.c
	$(CC) $(CFLAGS) -c qsort.c -o qsort.o

# Link the object files to create the final executable
qsort: $(OBJS_QSORT) $(OBJS)
	$(CC)  $(OBJS) $(OBJS_QSORT) -o qsort 

# Compile bsort.c into bsort.o
bsort.o: bsort.c
	$(CC) $(CFLAGS) -c bsort.c -o bsort.o

# Link the object files to create the final executable
bsort: $(OBJS_BSORT) $(OBJS)
	$(CC) $(OBJS) $(OBJS_BSORT) -o bsort 


clean:
	rm -f $(TARGET) $(OBJS) $(OBJS_BSORT) $(OBJS_QSORT)


