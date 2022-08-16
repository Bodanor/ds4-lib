CC=gcc
CFLAGS=-Wall -O3
ds4: ds4.c ds4.h main.c ansi-colors-code.h
	$(CC) $(CFLAGS) ds4.c main.c -o ds4

debug: debug.c
	$(CC) $(CFLAGS) debug.c -o debug