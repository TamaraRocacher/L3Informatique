#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[]){

  int i= 0;
  char *s;
  char *f;
  int n=5;//pour se deplacer dans path=...
 
  char buf[1024];
  
  getcwd(buf, 1023);
  
  while(env[i]!=NULL){
    s=strstr(env[i],"PATH=");
    if(s!=NULL && strcmp(env[i],s)==0)
      break;
    i++;
  }
  printf("%s\n",s);

  if(s !=NULL && s==env[i-1]){
    f=strtok(s,":");
    //puis comparer f et buf
  }
  
  while(f!=NULL){
 printf("%s\n",f);
    n+=strlen(f)+1;
    f = strtok(s,":");
    printf("%s\n",f);
    if (strcmp(f,buf)==0){
      printf("le repertoire courant est contenu dans PATH\n");
      return 0;
    }
  }
 printf("le repertoire courant n'est pas déclaré dans PATH\n");
  return 0;
}
 
