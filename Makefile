# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = main.c stack.c
OBJS = $(SRCS:.c=.o)
TARGET = main

# Default target
all: $(TARGET)

# Link the object files into the final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	del /f /q $(OBJS) $(TARGET).exe 2>nul || exit 0
