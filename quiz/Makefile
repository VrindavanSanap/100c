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

OBJS = cJSON.o quiz.o 

TARGET = quiz 
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

#bar.o: bar.c
#  $(CC) $(CFLAGS) -c bar.c

#foo.o: foo.c
#	$(CC) $(CFLAGS) -c foo.c

# Compilation
# $@ represents target
# $< represents first prerequisite(source file) 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Clean build files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
