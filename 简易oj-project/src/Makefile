CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra

OBJS = oj.o run.o

RM = rm -f

#.PHONY: clean

oj: $(OBJS)
	$(CC) $(CFLAGS) -o oj $(OBJS)
oj.o: oj.c run.h
	$(CC) $(CFLAGS) -c -o oj.o oj.c
run.o: run.c run.h
	$(CC) $(CFLAGS) -c -o run.o run.c
clean:
	$(RM) $(OBJS) oj
