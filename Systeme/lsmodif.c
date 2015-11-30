#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
  DIR* rep = opendir(argv[1]);
 
   if(rep==NULL){
    fprintf(stderr,"le repertoire n'est pas accessible");
    return -1;
   }
 
    char* chemin= (char *) malloc (1024);
   struct dirent* entree;
   struct stat etat;
   struct timeval time;
   int t=gettimeofday(&time,NULL);
 
   while(entree=readdir(rep)){
 
     strcat(strcat(strcpy(chemin,argv[1]),"/"),entree->d_name);
     if(stat(chemin, &etat)<0){
       fprintf(stderr,"erreur stat");
       return -1;
     }

     if((time.tv_sec-etat.st_mtime)<2*24*60*60){
      
       printf("%s\n",entree->d_name);
   
     }
   }
    free(chemin);
  closedir(rep);
  return 0;
}
