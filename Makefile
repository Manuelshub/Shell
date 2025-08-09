# Make file for Custom Shell Project

# Compiler
CC = gcc

# Compiler Flags
CCFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu18

TARGET = bin/hsh

build:
	$(CC) $(CCFLAGS) $(wildcard src/*.c) -o $(TARGET)

run: build
	./$(TARGET)
