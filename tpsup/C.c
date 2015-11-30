#include <stdio.h>
#define DEB_PRINT(...) do{\
    fprintf(stderr, "DEBUG -- ");\
    fprintf(stderr, ##__VA_ARGS__);\
  }while(0);

int isbigendian(){
  unsigned int i = 1;
  char *c = ( char *) &i;
  return c?0:1;
}

int main(){
  int i = 20;
  DEB_PRINT("hello world %d",i);
  return 0;
}
