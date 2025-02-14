# Makefile formaat
# target: dependencies  
#   action 
# 
# 
# 
# 
# 

# Compiler
CC = clang
# -Wall (Enable basic warnings)
# -Wextra (Enable more warnings)
# -O2 (Enable optimisations)
CFLAGS = -Wall -Wextra  #-O2

bar: bar.o foo.o
	$(CC) $(CFLAGS) bar.o foo.o -o bar

#bar.o: bar.c
#  $(CC) $(CFLAGS) -c bar.c

#foo.o: foo.c
#	$(CC) $(CFLAGS) -c foo.c

# Compilation
# $@ represents target
# $< represents first prerequisite(source file) 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
