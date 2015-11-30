#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void crible(int *in){
  if(-1==close(in[1])){//pas d ecriture dans in, deja remplit quand passé a crible
    fprintf(stderr,"erreur fermeture du decripteur en ecriture\n");
    exit(1);
  }
  int p, n;
  //tube vide
  if((n=read(in[0],&p,sizeof(int)))!= sizeof(int)){
    if(n==0){
      close(in[0]);// plus de lecture a faire
      return; // interrompre le programme crible
    }
    else
      exit(2);//erreur lecture
  }

  //tube non vide
  else{
    printf("%d ",p);
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
      close(in[0]); // fin de lecture dans in
      crible(out); // nouveau traitement, avec tube out en entree
      exit(0);
      break;
    default:
      close(out[0]); // pas de lecture dans out
      int i;
      while(read(in[0],(char *)&i, sizeof(int))==sizeof(int)){//lecture dans in, vers i
	if(i%p){
	  write(out[1], &i, sizeof(int));//ecriture dans out , de i
	}
      }
      close(in[0]);
      close(out[1]);
      int status;
      wait(&status);
      exit(status);
      break;
    }
  }
}

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
      crible(tube); // premier traitement, avec tube en entree
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
