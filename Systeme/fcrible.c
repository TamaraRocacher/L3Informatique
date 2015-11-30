#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
 
  int p, n;
  //tube vide
  if((n=read(0,&p,sizeof(int)))!= sizeof(int)){
    if(n==0){
      close(0);// plus de lecture a faire
      return 0; // interrompre le programme crible
    }
    else{
      printf("erreur lecture");
      exit(2);//erreur lecture
    }
  }

  //tube non vide
  else{
    printf(" %d ",p);
    fflush(stdout);
    int out[2];// creation tube de sortie
    if(pipe(out)==-1){
      fprintf(stderr,"erreur creation du tube\n");
      exit(3);
    }

    pid_t fils;
    switch(fils=fork()){
    case -1: 
      fprintf(stderr,"erreur de fork\n");
      exit(4);
      break;
    case 0://fils:
      close(0); // fin de lecture dans in
      close(out[1]);// descripteu on uilisé a fermer sinon deadlock!!!
      dup2(out[0],0);
      close(out[0]);
      if(execlp("fcrible", "fcrible",NULL)==-1){printf("pb exec");}; // nouveau traitement, avec tube out en entree
      return 0;
      break;
    default:
      close(out[0]); // pas de lecture dans out
      int i;
      while(read(0,(char *)&i, sizeof(int))==sizeof(int)){//lecture dans in, vers i
	if(i%p){
	  write(out[1], &i, sizeof(int));//ecriture dans out , de i
	}
      }
      close(0);
      close(out[1]);
      int status;
      wait(&status);
      return status;
      break;
    }
  }
}
