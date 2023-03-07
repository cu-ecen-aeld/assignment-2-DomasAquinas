# Check for the cross compiler
ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)
else
	CC = gcc
endif

# Compile the writer program
writer : writer.c
	$(CC) -c $^ -o $@

# Clean target - remove the compiled binary
.PHONY clean :
	rm -f writer
