CC      = gcc
CFLAGS  = -ffreestanding -nostdlib -I../include
LDFLAGS = -nostdlib

SRCS = ../src/crt.c			     \
	   ../src/internal/syscall.c \
       ../src/internal/brk.c     \
       ../src/string/strlen.c    \
       ../src/string/memset.c    \
       ../src/string/memcpy.c    \
       ../src/malloc.c           \
	   ../src/process.c          \
	   ../src/scanf.c			 \
	   ../src/printf.c			 \
       test.c


OBJS = $(SRCS:.c=.o)

build: $(OBJS)
	@ld $(OBJS) -o test

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: build
	@./test

clean:
	@rm -f $(OBJS) test
	@clear

.PHONY: run clean