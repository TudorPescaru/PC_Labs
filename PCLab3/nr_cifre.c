#include <stdio.h>

int nr_cifre(int n){
  if(n<=9)
   return 1;
  return 1+nr_cifre(n/10);
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d\n",nr_cifre(n));
}
