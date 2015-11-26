#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


void gest(int sig){

  printf("signal %d bien reçu!\n %s\n", sig, strerror(errno));
  
}
struct sigaction action;
void gest3(int sig){
  printf("signal %d bien reçu!\n", sig);
  action.sa_handler=SIG_DFL;
  sigaction(SIGINT, &action, NULL);
}


int  main(int argc, char** argv){
  action.sa_handler=gest;// gestionnaire definit
  //action.sa_handler=SIG_IGN;//ignorer le signal
  //action.sa_handler=gest3;//traiter une fois puis reprendre par defaut
  //sigaction(SIGINT, &action, NULL);// interruption ctrl + c

   sigaction(SIGSEGV,  &action, NULL);// signal seg fault
  //char str[1];//segment pile, qui peut s'agrandir
  //int* pi=NULL;
  //printf("%d",*pi);// SIGSEGV relancerait auto in/out ?, synchrone, lié a l'execution du code, boucle sur l'erreur
  //int j=*pi;
   fopen("toto.txt","r");
   //gestion de l'erreur, pas de signal!!
  printf("erreur %d bien reçu!\n %s\n", errno, strerror(errno));


  while(1);
}
