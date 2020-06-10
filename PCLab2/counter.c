#include <stdio.h>
#include <unistd.h>

int main(){
  for(int i=3;i>=1;i--){
    printf("%d \n",i);
    sleep(1);
  }
  printf("START\n");
  return 0;
}
