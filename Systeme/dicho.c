#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define TAILLE 1


char buf[TAILLE];

int main (int argc, char** argv){

  int f = open(argv[1],O_RDONLY);
   if(f==-1){
    fprintf(stderr,"fichier %s illisible!\n", argv[1]);
    return 2;
  }
   char x= argv[2][0],c;
   int deb=0,fin=lseek(f,0,SEEK_END)-1,mil=0,nbLu=0;

   do{
     mil=(deb+fin)/2;
     lseek(f,mil,SEEK_SET);
     nbLu=read(f,&c,TAILLE);
     
     if(c>x)
       fin=(mil-1);
     else if(c<x)
       deb= mil+1;
   }while(c!=x && deb<=fin);
   if(c==x)
     printf("Le caractère %c est en position %d \n", x,mil);
   else
     printf("Le caractère %c est absent de %s \n",x, argv[1]);

   close(f);
   return 0;
}
