# Interprocess Communication #

Couple of basic examples of IPC.


For now it is

- Anonymous Mapping of shared memory (for related processes only)
- FIFO (named pipes) for non related processes (test it with
			`run_fifo.sh`)

Synchronization is done via POSIX Semaphores.

# Basic glut renderer #

The example of initializing of a render loop is provided in `render.c`.
