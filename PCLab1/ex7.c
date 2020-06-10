#include <stdio.h>
#include <math.h>

int main(){
	float x,y;
	scanf("%f %f",&x,&y);
	if(fabs(x-y)<x*0.00001)
		printf("EQ\n");
	else
		printf("NOT EQ\n");
	return 0;
}
