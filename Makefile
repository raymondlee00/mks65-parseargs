ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	$(CC) -o parseargs main.o

main.o: main.c
	$(CC) -c main.c

run:
	./parseargs

clean:
	rm *.o
	rm parseargs
	rm *~

memcheck:
	valgrind --leak-check=yes ./parseargs