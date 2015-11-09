#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512 // taille buffer
#define NPACK 10 // nb de paquets
#define PORT 9931
#define SRV_IP "10.5.7.2"

void diep(char *s){
  perror(s);
  exit(1);
}

int main(int argc, char ** argv){
  struct sockaddr_in serv;
  int n_sent=0, n_read=0,fd, i, slen=sizeof(serv);//somme des tailles des attributs
  char buf[BUFLEN];

  /**** INITSOCKET() ****/
  //locale
  if((fd=socket(AF_INET, SOCK_DGRAM,0))==-1)
    diep("initSocket failed");

  //distante
  memset((char *)&serv, 0, slen);//cast en char * pour avoir tout les octets a 0 (copie mémoire); &var -> adresse memoire
  serv.sin_family =AF_INET;
  serv.sin_port=htons(PORT);// formate le num de port 
  if(inet_aton(SRV_IP,&serv.sin_addr)==0){//(cast IP et la fout ds sin_addr)
    fprintf(stderr,"inet_aton() failed\n");
    exit(1);
  }
  /**** FIN INITSOCKET() ****/

  char msg[512] ;
  memset(msg,'\0',512);
  printf("Tapez votre message (max. 512 caractères)\n");
  getline(&msg,512,0);
  //envoie de paquets, tant qu'il y en a cad NPACK fois
  for(i=0;i<NPACK;i++){
    
    printf("Envoie du paquet %d en cours\n", i+1);
    sprintf(buf,msg,i+1);
    if ((n_sent=sendto(fd, buf, BUFLEN, 0, &serv, slen))==-1)
      diep("sendto failed");

    if (n_sent!=BUFLEN) {
      printf("Sendto sent %d bytes\n",n_sent);
    }
    
    /* recevoir l'echo*/
    printf("attente reception\n");
    n_read = recvfrom(fd,buf,BUFLEN,0,NULL,NULL);
    if (n_read<0) {
      perror(" recvfrom failed");
      exit(1);
    }
    printf("recus\n");
    
    printf(" %d bits reçus\n",n_read);
    /* send what we got back to stdout */
    printf("message du serveur:%s\n",buf);
  }

  close(fd);
  return 0;
}
