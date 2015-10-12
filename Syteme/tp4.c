#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv){
  pid_t idPus = getpid();
  pid_t idParent= getppid();
  printf(" id processus: %d \n id parent %d \n", idPus, idParent);
  system("ps");

  pid_t newPus =fork();
  idPus = getpid();
  idParent= getppid();
  printf(" id processus: %d \n id parent %d \n", idPus, idParent);

  return 0;
}
