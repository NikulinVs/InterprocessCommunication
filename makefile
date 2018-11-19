CC=gcc
CFLAGS=-Wall -O3
LLIB=-lpthread
GRAPHLIB= -lglut -lGLU -lGL -lrt

all: render ipc_anon ipc_fifo_client ipc_fifo_host

ipc_anon: ipc_anon.o
ipc_fifo_client: ipc_fifo_client.o
ipc_fifo_host: ipc_fifo_host.o

.c.o:
#%.o: %.c
	$(CC) $(CFLAGS) -c $<

render: render.o
	$(CC) $< -o $@ $(GRAPHLIB)

.o:
	$(CC) $< -o $@ $(LLIB)
	rm *.o

.PHONY: clean

clean:
	rm -f `find . -maxdepth 1 -executable -type f`

# $^ $@ -- right and left side of : respectively

