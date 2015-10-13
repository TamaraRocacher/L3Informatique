#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv){
  pid_t idPus = getpid();
  pid_t idParent= getppid();
  printf(" id processus: %d \n id parent %d \n", idPus, idParent);
  system("ps");

  pid_t newPus =fork();
  if(newPus == -1){
    idPus = getpid();
    idParent= getppid();
    printf(" Vous etes dans le saint esprit!\n");
  }
  else if(newPus == 0){
    idPus = getpid();
    idParent= getppid();
    printf("Vous etes dans le fils:\n id processus: %d \n id parent %d \n", idPus, idParent);
  }
   else {
    idPus = getpid();
    idParent= getppid();
    printf("Vous etes dans le père:\n id processus: %d \n id parent %d \n", idPus, idParent);
  }
  return 0;
}
