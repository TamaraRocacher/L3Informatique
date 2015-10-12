#include <stdio.h>
#include <stdlib.h>

int main( int argc, char ** argv, char ** env){
  int i=0, j=0;
  printf("Vous avez passe %d parametres\n", argc);
  for(i; i<argc;i++){
    printf("argument %d : %s\n", i+1, argv[i]);
  }
  printf("Il y a %ld variables d'environnement\n", sizeof(env));
  for(j;j<sizeof(env);j++){
    printf("var. %d : %s\n", j+1, env[j]);
  }
}
