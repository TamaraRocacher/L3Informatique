#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int getIntFromChar( char c){
  int b=0, mask=0;
  while(mask<sizeof(char)*8){
    b+= c & (1<<mask++);
  }
  return b;
}

int main( int argc, char **argv){
  int i =0, j=0;
  if(argc==1)
    return 1;
  struct hostent* h = gethostbyname(argv[1]);
  if(h==NULL)
    return 1;
  //affichage du nom
  printf("nom officiel: %s \n", h->h_name);
  //affichage des alias
  printf("alias:\n");
  while(h->h_aliases[j]!= NULL){
    printf("%s\n",h->h_aliases[i]);
    j++;
  }
  //affichage du type d'adresse
  printf("type d'adresse: %d \n",h->h_addrtype);
  //affichage de la taille
  printf("taille: %d \n",h->h_length);
  // affichage des adresses
 while(h->h_addr_list[i]!= NULL){
    int a=getIntFromChar(h->h_addr_list[i][0]);
    int b=getIntFromChar(h->h_addr_list[i][1]);
    int c=getIntFromChar(h->h_addr_list[i][2]);
    int d=getIntFromChar(h->h_addr_list[i][3]);
    
    printf("adresse %d:  %d.%d.%d.%d\n",i+1,a,b,c,d);
    i++;
  }
  return 0;
}
