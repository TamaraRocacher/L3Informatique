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

#define NB_MAX_CLIENT 20 
#define BUFLEN 512

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

int max(int nb, int tab[], int fd){
  int i, maxi=fd;
  for(i=0; i<nb;i++){
    if(tab[i]>maxi)
      maxi=tab[i];
  }
  return maxi;
}

int main(int argc, char** argv){
  if(argc != 2) {
    printf(" %s PORT", argv[0]);
    return EXIT_FAILURE;
  }

  char buf[BUFLEN], bufSend[BUFLEN];
  int fd, l, i;
  memset(bufSend,0,BUFLEN);
  memset(buf,0,BUFLEN);
  
  int tabSocket[NB_MAX_CLIENT], nbSocket=0, bestEnch=0, client=0;
  memset(tabSocket,0,sizeof(int) * NB_MAX_CLIENT);
  fd_set a_surveiller;
  
  
  int port= atoi(argv[1]);
  int slen,j=0,deco=0,k;
  char nom[25][BUFLEN];
  memset(nom,0,25 * BUFLEN);

  struct sockaddr_in sockStruct;
  fd=initSocketTCP(&sockStruct,port);
  
  if((l=listen(fd,5))<0){
    perror("listen failed");
    return 2;
  }
  
  while(1){
    FD_ZERO(& a_surveiller);
    FD_SET(fd, & a_surveiller);
    
    for(i=0; i<nbSocket; i++){
      FD_SET(tabSocket[i], & a_surveiller);
    }
    struct timeval t;
    memset(&t,0, sizeof(t));
    t.tv_sec=50;

    int m =max(nbSocket,tabSocket,fd);
    select(m+1, &a_surveiller,NULL,NULL,&t);
   
    if(FD_ISSET(fd,&a_surveiller)) {
      printf("Accepte une connexion.\n");
      slen=sizeof(sockStruct);
      tabSocket[nbSocket++]=accept(fd,(struct sockaddr*) &sockStruct,&slen);
      if(tabSocket[nbSocket-1]<0)
	printf("accept = %d, failed with error : %d \n",tabSocket[--nbSocket], errno);
      else{
	memset(bufSend,0,BUFLEN);
	snprintf(bufSend,BUFLEN, "Bonjour,entrez votre nom:\n");
	send(tabSocket[i],bufSend,BUFLEN,0);

	 int ret=recv(tabSocket[i],&buf,BUFLEN,0);
	 //nom[tabSocket[i]]=buf;

	 // Copie du nom
	 for(j=0;j<BUFLEN;j++){
	   nom[tabSocket[i]][j]=buf[j];
	 }

	
	 printf("nom =%s \n", nom[tabSocket[i]]);
	 

	memset(bufSend,0,BUFLEN);
	snprintf(bufSend,BUFLEN, "Bienvenue %sL'enchère actuelle est de %d euros.\nEntrez votre enchère:\n",nom[tabSocket[i]], bestEnch);
	send(tabSocket[i],bufSend,BUFLEN,0);
	memset(buf,0,BUFLEN);
	printf("nom =%s \n", nom[tabSocket[i]]);// nom est lié a buf ???
      }
    }
    
    for(i=0; i<nbSocket; i++){
      if(FD_ISSET(tabSocket[i],&a_surveiller)){
	  int res=recv(tabSocket[i],&buf,BUFLEN,0);
	  printf("nom =%s \n", nom[tabSocket[i]]);
	  switch(res){
	  case -1: 
	    perror("receive failed");
	    
	  case 0://deconnexion
	    printf("Gestion d'une déconnexion\n");
	    deco = tabSocket[i];
	    close(tabSocket[i]);
	    tabSocket[i]=tabSocket[nbSocket-1];
	    nbSocket--;
	    memset(bufSend,0,BUFLEN);
	    snprintf(bufSend,BUFLEN, "%s a quitté l'enchère\n", nom[deco]);
	    for(i=0; i<nbSocket;i++){
	      send(tabSocket[i],bufSend, BUFLEN,0);
	    }
	    break;
	  default:
	    if(atoi(buf)>bestEnch){
	      bestEnch=atoi(buf);
	    
	      client=tabSocket[i];
	      printf(" buf = %d, bestEnch = %d, client = %d nom= %s \n",atoi(buf), bestEnch, client, nom[client]);
	      memset(bufSend,0,BUFLEN);
	      snprintf(bufSend,BUFLEN, "Nouvelle enchère de %d euros par %s\nEntrez votre enchère:\n",bestEnch, nom[client]);
	      for(i=0; i<nbSocket;i++){
		send(tabSocket[i],bufSend, BUFLEN,0);
	      }
	    }
	    else{
	      memset(bufSend,0,BUFLEN);
	      snprintf(bufSend,BUFLEN, "Votre enchère (%d euros) est incorrecte!Enchère actuelle %d euros\nEntrez une nouvelle enchère:\n",atoi(buf),bestEnch);
	      send(tabSocket[i],bufSend,BUFLEN,0);
	    }
	    
	  }
      }
    }
  }
  return 0;
}

