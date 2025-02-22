all: itoa

itoa: itoa.o syscalls.o
	ld itoa.o syscalls.o -o itoa
	strip itoa
	rm *.o

itoa.o: main.c
	cc -c -nostdlib main.c -o itoa.o

syscalls.o: syscalls.S
	as syscalls.S -o syscalls.o
