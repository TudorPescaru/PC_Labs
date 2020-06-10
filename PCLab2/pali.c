#include <stdio.h>

int main(){
	int x,y,n=0,c;
	scanf("%d",&x);
	y=x;
	while(y>0){
		c=y%10;
		y=y/10;
		n=n*10+c;
	}
	if(x==n)
		printf("Este palindrom\n");
	else 
		printf("Nu este palindorm\n");
	return 0;
}
