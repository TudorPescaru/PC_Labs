#include <stdio.h>

int main(){
  int n,d,ok,d1=0,d2=0,nr,p1,p2;
  scanf("%d",&n);
  ok=0;
  for(d=2;d<=n/2;d++)
    if(n%d==0){
      ok=1;
      break;
    }
  if(!ok)
    printf("CLOSEST PRIME IS %d\n",n);
  else{
    nr=n;
    nr++;
    ok=0;
    while(!ok){
      for(d=2;d<=nr/2;d++)
        if(nr%d==0)
          break;
      if(d>nr/2){
        p1=nr;
        ok=1;
      }
      else
        nr++;
    }
    d1=nr-n+1;
    nr=n;
    nr--;
    ok=0;
    while(!ok){
      for(d=2;d<=nr/2;d++)
        if(nr%d==0)
          break;
      if(d>nr/2){
        ok=1;
        p2=nr;
      }
      else
        nr--;
    }
    d2=n-nr+1;
    if(d1>d2)
      printf("CLOSEST PRIME IS %d\n",p2);
    else
      if(d2>d1)
        printf("CLOSEST PRIME IS %d\n",p1);
      else
        printf("CLOSEST PRIME ARE %d AND %d\n",p2,p1);
    }
    return 0;
}
