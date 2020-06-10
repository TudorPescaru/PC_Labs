#include <stdio.h>

int main(){
	int a=1<<31;
	char c = (char)a;
	printf("%d \n",c);
	//little endian
	return 0;
}


