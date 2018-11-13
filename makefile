all: ipc_anon ipc_fifo_client ipc_fifo_host

ipc_anon: ipc_anon.c
	gcc -Wall -O3  ipc_anon.c -o ipc_anon -lpthread
ipc_fifo_client: ipc_fifo_client.c
	gcc -Wall -O3  ipc_fifo_client.c -o ipc_fifo_client -lpthread
ipc_fifo_host: ipc_fifo_host.c
	gcc -Wall -O3  ipc_fifo_host.c -o ipc_fifo_host -lpthread

clean:
	rm -f ipc_anon ipc_fifo_client ipc_fifo_host
