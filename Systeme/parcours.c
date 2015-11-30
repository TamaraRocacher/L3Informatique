#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int parcours( char* rep, int indent){
  int i=0;
  DIR* repcourant = opendir(rep);

  if(repcourant==NULL){
    fprintf(stderr,"le repertoire %s n'est pas accessible", rep);
    return -1;
  }
  
  char* chemin= (char *) malloc (1024);
  struct dirent *entree;
  struct stat etat;
  while(entree = readdir(repcourant)){
    strcat(strcat(strcpy(chemin,rep),"/"),entree->d_name);
    if(lstat(chemin, &etat)<0){
      fprintf(stderr,"erreur stat");
      return -1;
    }
    if(S_ISDIR(etat.st_mode) && strcmp(".",entree->d_name) && strcmp("..",entree->d_name)){
      for(i=0; i<indent; i++){
	printf("\t");
      }
      printf("%s\n",entree->d_name);
      parcours(chemin,indent+1);
    }
  }
  free(chemin);
  closedir(repcourant);
  return 0;
}

int main(int argc, char **argv){
  printf("%s\n",argv[1]);
  return (parcours(argv[1],1));
}
