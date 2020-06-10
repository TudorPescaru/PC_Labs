#include <stdio.h>

int main(){
  int n,i,d,s,max=0,nr=0;
  scanf("%d",&n);
  for(i=2;i<=n;i++){
    s=0;
    for(d=2;d<i;d++){
      if(i%d==0)
       s=s+d;
    }
    if(s>max){
      max=s;
      nr=i;
    }
  }
  printf("%d\n",nr);
  return 0;
}
