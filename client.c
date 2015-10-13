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
  inet_aton("127.0.0.1", s->sin_addr.s_addr);

  /*t b=bind(fd, (struct sockaddr *)s, sizeof(*s));
  if (b<0){
    fprintf(stderr,"bind bug\n");
    exit(2);
  }*/
  return fd;
}

int main (int argc, char** argv, char** env){
  if (argc <3) {
    fprintf(stderr,"Usage: %s Serveur port\n", argv[0]);
    return 1;
  }
  struct sockaddr_in sockStruct;
  struct hostent *h;
  int port = atoi(argv[2]);
  int sockServ = initSocketTCP(&sockStruct,port);
  int sockDist;

  
  //connect
  h = gethostbyname(argv[1]);
  //memcpy(&sockStruct.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  
  int c = connect(sockServ, (struct sockaddr*) &sockStruct, sizeof(sockStruct));
  if(c < 0) {
    fprintf(stderr, "Erreur de connexion\n");
    return 2;
  }
  char buf[15];
  int r = read(sockServ, buf, 12);

  for(int i = 0; i<r; i++) {
    printf("%c", buf[i]);
  }
  printf("\n");
  

  return 0;
}
