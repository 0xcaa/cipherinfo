CC=gcc
CFLAGS=-g -Wall -pedantic 
OBJS=main.o  identify.o usage.o
PREFIX=/usr/local

sipher: $(OBJS)
	$(CC) -o cipherinfo $(OBJS)

main.o: identify.h usage.h

clean:
	rm cipherinfo $(OBJS)

install:
		cp main $(DESTDIR)$(PREFIX)/bin/cipherid

uninstall:	
		rm main $(DESTDIR)$(PREFIX)/bin/cipherid
