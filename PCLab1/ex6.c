#include <stdio.h>
#include <math.h>

int main(){
	float x,y;
	scanf("%f %f",&x,&y);
	printf("%.2f %.2f\n",(x+y+fabs(x-y))/2,(x+y-fabs(x-y))/2);
	return 0;
}
