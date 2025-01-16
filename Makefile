
CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lncurses

objects = main.o card.o screen.o input.o 
all: $(objects)
	$(CC) $^ -o husk $(LDFLAGS)

$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

%.c:
	touch $@

clean:
	rm -f *.o skald

husk: husk.o
	gcc husk.o -o husk -Wall
husk.o: main.c
	gcc main.c card.c screen.c input.c -o husk.o -lncurses
