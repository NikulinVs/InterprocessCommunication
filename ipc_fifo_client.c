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
  char buf[BUFFER_SIZE];
  int num_read;

  sem = sem_open("/semsem", 0);
  if(sem == SEM_FAILED)
  {
    printf("Something went wrong with semaphore...\n");
  }

  fifo_fd = open("testfifo", O_RDONLY);

  num_read = read(fifo_fd, buf, BUFFER_SIZE);
  if(num_read < 0)
  {
    printf("Error in reading!\n");
  }

  printf("The host have sent me the following: %s\n", buf);

  sem_post(sem);

  close(fifo_fd);

  sem_close(sem);


  return 0;
}
