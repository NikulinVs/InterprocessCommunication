FLAGS=-Wall -O3
CC=gcc
LIBS=-lpthread

ipc: ipc.c
	$(CC) $(FLAGS)  ipc.c -o ipc $(LIBS)
