#include <stdio.h>
#include <sys/types.h>
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
  int pid;
  char* buf;
  sem_t* sem;

  buf = (char*)mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
  sem = sem_open("/semsem", O_CREAT | O_EXCL, S_IRWXU, 0);
  if(sem == SEM_FAILED)
  {
    printf("Something went wrong...\n");
  }

  pid = fork();
  if(pid != 0)
  {
    sem_wait(sem);
    printf("%s", buf);
    munmap(buf, BUFFER_SIZE);
    sem_close(sem);
    sem_unlink("/semsem");
  }
  else if(pid == 0)
  {
    sem = sem_open("/semsem", 0);
    if(sem == SEM_FAILED)
    {
      printf("Something went wrong...\n");
    }

    strcpy(buf, "hello\n");
    sem_post(sem);
    sem_close(sem);
  }
  else
  {
    printf("Fork failed!\n");
  }

  return 0;
}
