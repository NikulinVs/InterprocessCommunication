CC=gcc
CFLAGS=-Wall -O3
LLIB=-lpthread

all: ipc_anon ipc_fifo_client ipc_fifo_host

ipc_anon: ipc_anon.o
ipc_fifo_client: ipc_fifo_client.o
ipc_fifo_host: ipc_fifo_host.o

.c.o:
#%.o: %.c
	$(CC) $(CFLAGS) -c $<

.o:
	$(CC) $< -o $@ $(LLIB)
	rm *.o

.PHONY: clean

clean:
	rm -f `find . -perm +111  -type f -maxdepth 1`

# $^ $@ -- right and left side of : respectively

