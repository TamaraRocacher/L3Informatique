#include "anagram.h"

#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>


#define BUFLEN 1024

int initSocketTCPclient(struct sockaddr_in* s, int p, char* srvIp){
  int fd =  socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    fprintf(stderr, "init socket failed\n");
    exit(1);
  }
  
  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  struct hostent* h = gethostbyname(srvIp);
  memcpy(&s->sin_addr, h->h_addr_list[0], h->h_length);
 
  return fd;
}


int main (int argc, char** argv){
  if (argc !=3) {
    fprintf(stderr,"Usage: %s Serveur port\n", argv[0]);
    return 1;
  }
  struct sockaddr_in s;
  struct hostent *h;

  int port = atoi(argv[2]);
  char buf[BUFLEN];
  char* srvIp=argv[1];
  int sockServ = initSocketTCPclient(&s,port, srvIp);

  int size,c,rec,max,fin=0;
  fd_set a_surveiller;
  if(STDIN_FILENO>sockServ){
    max=STDIN_FILENO;
  }
  else{
    max=sockServ;
  }
  size= sizeof(s);
  c = connect(sockServ, (struct sockaddr*) &s, size);
  if(c < 0) {
    fprintf(stderr, "connexion failed\n");
    return 2;
  }
  while(!fin){
    FD_ZERO(& a_surveiller);
    FD_SET(sockServ,& a_surveiller);//socket pour l'affichage des receptions
    FD_SET(STDIN_FILENO, &a_surveiller);//socket pour le traitement clavier
    
    
    select(max+1,&a_surveiller,NULL,NULL,NULL);
    
    if(FD_ISSET(sockServ,&a_surveiller)){// serveur a envoyer
      if((rec=recv(sockServ,buf,BUFLEN,0))<0){
	printf("receive failed");
      }
      printf("%s\n", buf);
    }
    if(FD_ISSET(STDIN_FILENO, &a_surveiller)){
      fgets(buf, BUFLEN, stdin);
      buf[strlen(buf) - 1] = '\0';
      send(sockServ, buf, BUFLEN, 0);
      if(!strcmp(buf, "FIN"))
	fin = 1;
    }
  }
  
  close(sockServ);
  return 0;
}
