#include <stdio.h>

int main(){
	int x,i,ok=1;
	scanf("%d",&x);
	for(i=2;i<=x/2;i++)
		if(x%i==0)
			ok=0;
	if(ok)
		printf("Este prim\n");
	else 
		printf("Nu este prim\n");
	return 0;
}
