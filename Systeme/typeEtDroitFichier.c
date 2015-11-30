#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    int main(int argc, char** argv){
      struct stat etat;
      if(stat(argv[1],&etat)==-1){// rempli la struct (buf) etat avec les info du rep passé en param
	fprintf(stderr,"%s n'existe pas",argv[1]);
	exit(2);
      }
      //type
      if(S_ISREG(etat.st_mode)){
	printf("-");
      }
      else if(S_ISDIR(etat.st_mode)){
	printf("d");
      }
      else if(S_ISLNK(etat.st_mode)){
	printf("l");
      }
      //droits user
      if(etat.st_mode & S_IRUSR){
	printf("r");
      }
      else
	printf("-");
      
      if(etat.st_mode & S_IWUSR){
	printf("w");
      }
      else
	printf("-");
      if(etat.st_mode & S_IXUSR){
	printf("x");
      }
      else
	printf("-");

      //droit groupe
      
      if(etat.st_mode & S_IRGRP){
	printf("r");
      }
      else
	printf("-");
      
      if(etat.st_mode & S_IWGRP){
	printf("w");
      }
      else
	printf("-");
      if(etat.st_mode & S_IXGRP){
	printf("x");
      }
      else
	printf("-");
      
      
      //droits other
      if(etat.st_mode & S_IROTH){
	printf("r");
      }
      else
	printf("-");
      
      if(etat.st_mode & S_IWOTH){
	printf("w");
      }
      else
	printf("-");
      if(etat.st_mode & S_IXOTH){
	printf("x");
      }
      else
	printf("-");
	
      printf("\n");
      return 0;
    
    }
    
