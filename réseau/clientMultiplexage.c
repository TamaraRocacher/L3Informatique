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

#define BUFLEN 250

int initSocketTCP(struct sockaddr_in* s, int p, char* srvIp){
  int fd =  socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(fd<0){
    fprintf(stderr, "socket bug\n");
    exit(1);
  }
  
  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  //Si bug, ip=INADDR_ANY
  //inet_aton(srvIp, &(s->sin_addr));
  struct hostent* h = gethostbyname(srvIp);
  memcpy(&s->sin_addr, h->h_addr_list[0], h->h_length);
 

 
  return fd;
}

int main (int argc, char** argv){
  if (argc !=3) {
    fprintf(stderr,"Usage: %s Serveur port\n", argv[0]);
    return 1;
  }
  struct sockaddr_in sockStruct;
  struct hostent *h;

  int port = atoi(argv[2]);
  char* srvIp=argv[1];
  int sockServ = initSocketTCP(&sockStruct,port, srvIp);

  fd_set a_surveiller;

  
  //connect

  //memcpy(&sockStruct.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  int size;
  size= sizeof(sockStruct);
  
  
  int c = connect(sockServ, (struct sockaddr*) &sockStruct, size);
  if(c < 0) {
    fprintf(stderr, "Erreur de connexion\n");
    return 2;
  }
  char buf[BUFLEN];
  int ret;
  int max= sockServ > STDIN_FILENO ? sockServ : STDIN_FILENO;
  int cont = 1;
  while(cont){
    FD_ZERO(& a_surveiller);
    FD_SET(sockServ,& a_surveiller);
    FD_SET(STDIN_FILENO, &a_surveiller);

    select(max+1,&a_surveiller,NULL,NULL,NULL);

    if(FD_ISSET(sockServ,&a_surveiller)){// serveur a envoyer
      if((ret=recv(sockServ,buf,BUFLEN,0))<0){
	printf("receive failed");
      }
      printf("%s\n", buf);
    }
    if(FD_ISSET(STDIN_FILENO, &a_surveiller)){
      fgets(buf, BUFLEN, stdin);
      buf[strlen(buf) - 1] = '\0';
      send(sockServ, buf, BUFLEN, 0);
      if(!strcmp(buf, "!exit"))
	cont = 0;
    }
  }

  close(sockServ);
  /*
  int r = read(sockServ, buf, 12);

  for(int i = 0; i<r; i++) {
    printf("%c", buf[i]);
  }
  printf("\n");
  */

  close(sockServ);
  return 0;
}
