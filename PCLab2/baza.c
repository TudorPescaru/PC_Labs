#include <stdio.h>

int main(){
  int p=1,n,c,nr=0;
  scanf("%d",&n);
  while(n>0){
    c=n%10;
    nr=nr+c*p;
    p=p*2;
    n=n/10;
  }
  printf("-->%d-->",nr);
  /*
  while(nr>0){
    if(nr-p<0){
     p=p/2;
     n=n*10;
    }
    else {
      nr=nr-p;
      p=p/2;
      n=n*10+1;
    }
    
  }
  */
  int r=0;
  p=1;
  while(nr>0)
  {
    r=nr%2;
    nr/=2;
    n=n+r*p;
    p*=10;
  }
  printf("%d\n",n);
  return 0;
}
