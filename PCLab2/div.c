#include <stdio.h>

int main(){
	int x,i;
	scanf("%d",&x);
	printf("1,");
	for(i=2;i<=x/2;i++)
		if(x%i==0)
			printf("%d,",i);
	if(x!=1)
		printf("%d\n",x);
	return 0;
}
