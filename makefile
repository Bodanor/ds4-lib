CC=gcc
CFLAGS=-Wall -O3
AR=ar
ARFLAGS=-cvq
ds4: ds4.c ds4.h main.c ansi-colors-code.h dslib.a
	$(CC) $(CFLAGS) main.c dslib.a -o ds4

debug: debug.c
	$(CC) $(CFLAGS) debug.c -o debug

dslib.a: ds4.c ds4.h
	$(CC) $(CFLAGS) ds4.c -c
	$(AR) $(ARFLAGS) dslib.a ds4.o
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf ds4
	rm -rf debug

	