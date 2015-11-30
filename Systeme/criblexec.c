#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
  if(argc!=2){
    fprintf(stderr," %s n\n",argv[0]);
    exit(5);
  }
  int borne=atoi(argv[1]);
  if(borne<2){
    fprintf(stderr,"valeur de n trop petite! (1<n)\n");
    exit(6);
  }
  int tube[2];
  pid_t fils;
  if(pipe(tube)==-1){
    fprintf(stderr,"erreur creation du tube\n");
    exit(7);
  }
  switch(fils=fork()){
     case -1: 
      fprintf(stderr,"erreur de fork\n");
      exit(4);
      break;
    case 0://fils:
      close(tube[1]);
      dup2(tube[0],0);
      close(tube[0]);
      if(execlp("./fcrible", "fcrible",NULL)==-1){printf("pb exec\n");}; // premier traitement, avec tube en entree
      return 0;
      break;
    default:
      close(tube[0]); // pas de lecture dans tube
      for(int i=2;i<=borne;i++){
	write(tube[1],(char*) &i, sizeof(int));//ecriture dans tube , de i, de 2 a borne(n)
      }
      close(tube[1]);
      int etat;
      wait(&etat);
      printf("\n");
      return etat;
      break;
  }
}
