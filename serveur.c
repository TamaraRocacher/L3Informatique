#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <netdb.h>


int initSocketTCP(struct sockaddr_in* s, int p){
  int fd =  socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(fd<0){
    fprintf(stderr, "socket bug\n");
    exit(1);
  }

  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  //Si bug, ip=INADDR_ANY
  s->sin_addr.s_addr = htonl(INADDR_ANY);

  int b=bind(fd, (struct sockaddr *)s, sizeof(*s));
  if (b<0){
    fprintf(stderr, "bind bug\n");
    exit(2);
  }
  return fd;
}

int main (int argc, char **argv, char **env){
  if (argc <2){
    fprintf(stderr,"Vous devez entrer un numero de port!\n");
    return 1;
  }

  struct sockaddr_in sockStruct;
  int port = atoi(argv[1]);
  int sockLoc = initSocketTCP(&sockStruct, port);
  int sockDist;

  //listen
  int l=listen(sockLoc, 5);
  if (l<0){
    fprintf(stderr,"va te faire foutre dixit le serveur");
    return 2;
  }

  //accept : struct sockaddr(arg 2) pour socket dist permet de recuperer IP et autre
  printf("server bound to port %u 0x%x \n", ntohs(sockStruct.sin_port), sockStruct.sin_port);
  sockDist = accept(sockLoc,0,0); // while/fork si file d'attente

  
  write(sockDist, "Hello World", 12); 
  
  close(sockDist);
  close(sockLoc);
  return 0;
}
