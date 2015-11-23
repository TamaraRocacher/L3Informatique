#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

#define NB_MAX_CLIENT 20 

int initSocketTCP(struct sockaddr_in* s, int p){
  //creation socket
  if(int fd =  socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)<0){
    perror ("socket bug\n");
    exit(1);
  }
  
  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  s->sin_addr.s_addr = htonl(INADDR_ANY);
  
  int b=bind(fd, (struct sockaddr *)s, sizeof(*s));
  if (b<0){
    fprintf(stderr, "bind bug\n");
    exit(2);
  }
  return fd;
}

int main(int argc, char** argv){
  if(argc < 3)
    printf(" %s SERVEUR PORT", argv[0]);
  
  int tabSocket[NB_MAX_CLIENT], nbSocket=0, bestEnch=0, client=0;
  memset(tabSocket,0,sizeof(tabSocket));
  fd_set a_surveiller;
  char buf[4];
  
  int port= atoi(argv[1]);

  struct sockaddr_in sockStruct;
  int fd=initSocketTCP(&sockStruct,port);
  
  if(int l=listen(fd,5)<0){
    perror("listen failed");
    return 2;
  }
  
  while(1){
    FD_ZERO(& a_surveiller);
    FD_SET(fd, & a_surveiller);
    
    for(int i=0; i<nbSocket; i++){
      FD_SET(tabSocket[i], & a_surveiller);
    }
    struct timeval t;
    memset(&t,0, sizeof(t));
    t.tv_sec=3;

    select(max(NB_MAX_CLIENT,tabSocket)+1, &a_surveiller,NULL,NULL,t);
   
    if(FD_ISSET(fd,&a_surveiller))
      tabSocket[nbSocket++]=accept(fd,&sockStruct,/*0?*/);

    for(int i=0; i<nbSocket; i++){
      if(FD_ISSET(tabSocket[i];&a_surveiller){
	  int res=recv(tabSocket[i],
  
  
}
