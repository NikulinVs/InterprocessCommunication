#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>

#define BUFFER_SIZE 80

int main(void)
{
  sem_t* sem;
  int fifo_fd;

  sem = sem_open("/semsem", O_CREAT | O_EXCL, S_IRWXU, 0);
  if(sem == SEM_FAILED)
  {
    printf("Something went wrong with semaphore...\n");
  }

  if(mkfifo("testfifo", S_IRWXU) != 0)
  {
    printf("Something went wrong with creating a fifo...");
  }

  fifo_fd = open("testfifo", O_WRONLY);

  write(fifo_fd, "hello", 5);

  sem_wait(sem);

  close(fifo_fd);

  sem_close(sem);
  sem_unlink("/semsem");

  unlink("testfifo");

  return 0;
}
