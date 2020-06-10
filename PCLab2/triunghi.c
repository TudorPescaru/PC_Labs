#include <stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a<(b+c) && b<(a+c) && c<(a+b))
		printf("Sunt laturile unui triunghi. \n");
	else
		printf("Nu sunt laturile unui triunghi. \n");
	return 0;
}
