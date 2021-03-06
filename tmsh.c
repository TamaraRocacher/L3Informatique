#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

uid_t e_uid;
extern errno;

#define couleur(param) printf("\033[%sm",param)

void PS1();

int main(int argc, char* argv[], char* env[]) 
{  
  int i = 0, j = 0;
  int status;
  char** args;
  char *token;
  int l;
  
  char s[1024];

  do {
    PS1(); // Affiche la ligne PS1 précédant la commande à executer
    fgets(s,1024,stdin);
    //fprintf(stderr,"s= %s\n",s);
    
    if((l = strlen(s))> 0 && s[l-1] == '\n') {
      s[l-1] = '\0';
    }
  
    
    if(s!=NULL)
      token = strtok(s," ");
    //fprintf(stderr,"token = %s\n",token);
    
    
    args = (char**)malloc(8*sizeof(char*));
    while(token != NULL) {
      args[i] = (char *)malloc(8*sizeof(char));
      args[i] = token;
      i++;
      //printf("rrr : %s\n",token);
      token = strtok(NULL, " ");
      //args = realloc(args, i+1*sizeof(char*));
    }
    args[i] =(char *) NULL;
    /* Test tableau
       for(int j=0; j<i;j++){
       printf(" arg[%d]= %s\n", j, args[j]);
       }*/
    

    // EXECUTION
    switch(fork()) {
    case -1 :
      fprintf(stderr, "Erreur ");
      break;
    case 0 :
      if (execvp(*args,args)<0){
	fprintf(stderr,"exec failed : %d\n", errno);
	exit(1);
      }
      break;
    default:
      wait(&status);
      break;
    }
  
    j=0;
    while(j<i-1) {
      free(args[j]);
      j++;
    }
  }while(s != "exit");

  free(args);
  return 0;
}


void PS1() {
  couleur("34");
  printf("tmsh]|[ ");
  couleur("0");
  fflush(stdout);
}
