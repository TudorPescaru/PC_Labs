#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(0x1234);
  for(int i=1;i<=5;i++)
    printf("%d ",rand());
  printf("\n");
  return 0;
}
