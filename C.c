#include <stdio.h>
#include <netdb.h>
#define DEB_PRINT(...) do{\
    fprintf(stderr, "DEBUG -- ");\
    fprintf(stderr, ##__VA_ARGS__);\
  }while(0);

int isbigendian(){
  unsigned int i = 1;
  char *c = ( char *) &i;
  return c?0:1;
}
int getIntFromChar( char c){
  int b=0, mask=0;
  while(mask<sizeof(char)*8){
    b+= c & (1<<mask++);
  }
  return b;
}

//affichage adresse ip par chaine de 4 char:
int afficherIP(char* ip){
  switch(0){
    do{
    default:
      printf(".");
    case 0:
      printf("%d",getIntFromChar(*ip));
    }while(*ip);
  }
  printf("\n");
  return 0;
}

int main(){
  struct hostent *h = gethostbyname("localhost");
  afficherIP(h->h_addr_list[0]);
  return 0;
}
