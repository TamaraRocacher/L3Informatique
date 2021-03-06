#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct sigaction action;
void gest(int sig){
  static int cpt=1;
  switch(cpt){
  case 1:
    printf("Repondez + vite!\n");
    cpt++;
    alarm(5);
    return;
    break;
  case 2:
    printf("Repondez ++ vite!\n");
    cpt++;
    alarm(3);
    return;
    break;
  case 3:
    printf("Trop tard!\n");
    exit(1);
    break;
  }
}

int main(int argc, char** argv){
  action.sa_handler=gest;
  action.sa_flags=SA_RESTART; // pour relancer le scanf
  sigaction(SIGALRM, &action, NULL);
  printf("Entrez un entier en 10 sec:\n");
  alarm(10);
  int i;
  scanf("%i", &i);
  alarm(0);
  printf("Bravo, vous avez tapé: %d\n",i);
  return 0;
	    
}
