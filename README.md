# Interprocess Communication #

Couple of basic examples of IPC.


For now it is

- Anonymuos Mapping of shared memory (for related processes only)
- FIFO (named pipes) for non related processes (test it with
			`run_fifo.sh`)

Synchronization is done via POSIX Semaphores.


Please notice that `makefile` is **not optimized at all**. In you project you
should use wildcards, variables and incorporated bash commands to make the
makefile as tiny as possible.
