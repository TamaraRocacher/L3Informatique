#include "anagram.h"

#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFLEN 1024



int initSocketTCP(struct sockaddr_in* s, int p){
  int fd =  socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    fprintf(stderr, "init socket failed\n");
    exit(1);
  }

  //remplissage struct
  s->sin_family = AF_INET;
  s->sin_port = htons(p);
  s->sin_addr.s_addr = htonl(INADDR_ANY);

  int b=bind(fd, (struct sockaddr *)s, sizeof(*s));
  if (b<0){
    fprintf(stderr, "bind failed\n");
    exit(2);
  }
  return fd;
}




int main(int argc, char** argv){

  //verification des arguments
  if(argc != 2) {
    printf(" %s PORT", argv[0]);
    return EXIT_FAILURE;
  }

  struct sockaddr_in s;
  char buf[BUFLEN],mot[50];
  memset(buf,0,BUFLEN);
  memset(mot,0,50);
  int port=atoi(argv[1]), sockClient,l,slen,tabJoueurs[1][2],rec,fin=0,i=0;
  int sock = initSocketTCP(&s, port);

  if((l=listen(sock,5))<0){
    fprintf(stderr, "listen failed\n");
    exit(3);
  }
  //accepter le client
  slen=sizeof(s);
  if((sockClient = accept(sock,(struct sockaddr*)&s,&slen))<0){
    fprintf(stderr,"accept failed with error: %d\n",errno);
    exit(4);
  }
  //identification du client dans tabJoueurs
  send(sockClient, "Bienvenue, veuillez vous identifier:\n",40,0);
  if((rec=recv(sockClient,&buf,BUFLEN,0))<0){
    fprintf(stderr,"receive failed\n");
  }
  tabJoueurs[0][0]=atoi(buf);// pour stocker l ID du client
  tabJoueurs[0][1]=0; // nb de points du joueur
  memset(buf,0,BUFLEN);
  snprintf( buf,BUFLEN,"Bienvenue %d, le jeu va commencer:\n",tabJoueurs[0][0]);
  send(sockClient,&buf,BUFLEN,0);
 
  //initialisation du jeu
  dict_t dico;
  anagram_t anagram;
  int nbLignesDico= initialise_dico(&dico,"dictionnaire");

  if(nbLignesDico<0){
    fprintf(stderr,"init dico failed\n");
    exit(5);
  }
  int nbSolution, estSolution;
  int k=0;
  while(tabJoueurs[0][1]<5){
    k++;
    printf("%d\n",k);
    initialise_dico(&dico,"dictionnaire");
    nbSolution=initialise_anagramme(&anagram,&dico);
    printf("anagramme %d\n",k);
    memset(buf,0,BUFLEN);
    snprintf(buf,BUFLEN," %s",anagram.mot_courant);
    send(sockClient,&buf,BUFLEN,0);
    memset(buf,0,BUFLEN);
    
    if((rec=recv(sockClient,&buf,BUFLEN,0))<0){
        fprintf(stderr,"receive failed\n");
    }
    for(i=0; i<rec-1;i++){
      mot[i] = buf[i];
    }
    mot[i]='\0';
    memset(buf,0,BUFLEN);
    snprintf(buf,BUFLEN," %d - %s",tabJoueurs[0][0],mot);
    send(sockClient,&buf,BUFLEN,0);
     memset(buf,0,BUFLEN);

     //commande FIN
    if(!strcmp(mot,"FIN")){
      send(sockClient,"Déconnexion en cours...",30,0);
      close(sockClient);
    }

    if((estSolution = est_une_solution(&anagram,mot))==1){
      snprintf(buf,BUFLEN,"Bravo %d, vous gagnez 1 point!\n",tabJoueurs[0][0]);
      send(sockClient,&buf,BUFLEN,0);
      tabJoueurs[0][1]++;
    }
  
  }
  return 0;
}
