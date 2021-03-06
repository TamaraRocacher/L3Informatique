#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define TAILLE 1024


char buf[TAILLE];

int main (int argc, char** argv){
  if(argc!=3){
    fprintf(stderr,"Vous devez spécifier 3 arguments!\n");
    return 1;
  }
  int s=open(argv[1],O_RDONLY);
  if(s==-1){
    fprintf(stderr,"fichier %s illisible!\n", argv[1]);
    return 2;
  }
  int d=open(argv[2], O_CREAT | O_TRUNC | O_WRONLY,0640);
  if(d==-1){
    fprintf(stderr,"fichier %s non inscriptible!\n",argv[2]);
    return 3;
  }
  int nbLu;
  while((nbLu=read(s,buf,TAILLE))!=0){
    write(d,buf,nbLu);
  }
  close(s);
  close(d);
  return 0;
}
