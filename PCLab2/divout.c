#include <stdio.h>

int main(){
  int n=0,d,nr=0,ok;
  while(n>=0){
    scanf("%d",&n);
    if(n<0)
     break;
    ok=1;
    printf("OUT: ");
    for(d=2;d<=n/2;d++){
      if(n%d==0){
        ok=0;
        if(!ok)
         printf("%d ",d);
      }
    }
    if(ok){
     printf("PRIM");
     nr++;
   }
   printf("\n");
  }
  printf("OUT: S-au gasit %d numere prime.\n",nr);
  return 0;
}
