//TCP : pas de pertes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#define BUFLEN 1024

int initSocketTCP(struct sockaddr_in* s, int p){
  int fd;
  
  //creation socket
  if((fd =  socket(AF_INET,SOCK_STREAM,0))<0){
    perror ("socket bug\n");
    exit(1);
  }
  
  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  s->sin_addr.s_addr = htonl(INADDR_ANY);
  
  int b=bind(fd, (struct sockaddr *)s, sizeof(*s));
  if (b<0){
    perror("bind bug");
    //fprintf(stderr, "bind bug\n");
    exit(2);
  }
  return fd;
}


int main(int argc, char** argv){
  if(argc != 2) {
    printf(" %s PORT", argv[0]);
    return EXIT_FAILURE;
  }
  
  char buf[BUFLEN];
  memset(buf,0,BUFLEN);
  
  int sock,sockLiee,l,i,port= atoi(argv[1]),slen,j=0,deco=0,k;
  int n = 0;
  int tailleFichier = 0;
  int tailleEnvoyee = 0;
  struct stat infos;
  int src;
  int ecrit;

  struct sockaddr_in sockStruct;

  sock=initSocketTCP(&sockStruct,port);
  slen=sizeof(sockStruct);

  if((l = listen(sock, 5)) <0) {
    perror("listen");
    exit(2);
  }

  sockLiee=accept(sock,(struct sockaddr*) &sockStruct, &slen);
  if(sockLiee <0) {
    perror("Accept: ");
    exit(1);
  }

  //snprintf(buf,BUFLEN,"Veuillez entrer le nom du fichier a telecharger:\n");
  //send(sock,buf,BUFLEN,0);
  send(sockLiee, "Veuillez entrer le nom du fichier a telecharger:\n",49,0);
  recv(sockLiee, buf, BUFLEN,0);
  printf("%s\n", buf);
  
  //char c = 'a';
  //for(i = 0; (c=buf[i]) != '\n';i++);
  //buf[i]='\0';
  buf[strlen(buf) - 2] = '\0';
  i=0;
  while( i < strlen(buf) ) {
    printf("CHAR:%d\n", buf[i]);
    i++;
  }
  
  char *nomFichier = buf; //peut causer des bugs sans connaitre la taille du nom de fichier reçu

  if((src = open(nomFichier, O_RDONLY)) == -1) {
    send(sockLiee, "Le fichier n'existe pas\n",24,0);
  }
  else { //Le fichier existe
    fstat(src, &infos);
    tailleFichier = infos.st_size;

    while(tailleEnvoyee < tailleFichier) {
      if((n = read(src, buf, BUFLEN)) <0) {
	perror("Read");
	exit(5);
      }
      tailleEnvoyee +=n;
      printf("Taille du lot transmis: %d\n", n);

      if((ecrit = write(sockLiee, buf, n)) !=n) {
	perror("write");
	exit(6);
      }
    }
    close(src);
  }
  
  return 0;
}
