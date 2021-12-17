#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  int idParent = getpid();
  
  for (int i=0; i<5; i++){
    if (getpid() == idParent)
    {
      fork();
      if (getpid() != idParent)
      {
        printf("Soy hijo con PID %d y mi padre tiene PID %d\n", (int) getpid(),(int) getppid());
      }
      else 
      {
         wait(NULL);
      }
    }
  }
  return 0;
}
