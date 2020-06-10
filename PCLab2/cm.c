#include <stdio.h>

int main(){
	int a,b,r,p;
	scanf("%d %d",&a,&b);
	p=a*b;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	printf("CMMDC=%d\n",a);
	printf("CMMMC=%d\n",(p/a));
	return 0;
}
