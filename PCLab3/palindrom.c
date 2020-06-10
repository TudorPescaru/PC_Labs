#include <stdio.h>

int nr_cifre(int n){
  if(n<=9)
   return 1;
  return 1+nr_cifre(n/10);
}

int power(int a,int b){
  int p;
  if(b==0)
   return 1;
  else{
    if(b%2==0){
      p=power(a,b/2);
      return p*power(a,b/2);
    }
    else{
      p=power(a,b/2);
      return a*p*power(a,b/2);
    }
  }
}

int reverse(int n){
    if(n==0)
     return 0;
    else
     return (n%10)*power(10,(nr_cifre(n)-1))+reverse(n/10);
}

int main(){
  int n,nr;
  scanf("%d",&n);
  nr=reverse(n);
  if(nr==n)
   printf("PALINDROM\n");
  else
   printf("NU ESTE PALINDROM\n");
  return 0;
}
