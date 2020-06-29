CC=gcc
CFLAGS=-g -Wall -pedantic 
OBJS=main.o  identify.o
PREFIX=/usr/local

sipher: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: identify.h

clean:
	rm main $(OBJS)

install:
		cp main $(DESTDIR)$(PREFIX)/bin/cipherid

uninstall:	
		rm main $(DESTDIR)$(PREFIX)/bin/cipherid
