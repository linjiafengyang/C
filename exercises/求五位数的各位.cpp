#include <stdio.h>
int main(){
	int x,a,b,c,d,e;
	scanf("%d",&x);
	a=x/10000;
	b=(x-a*10000)/1000;
	c=(x-a*10000-b*1000)/100;
	d=(x-a*10000-b*1000-c*100)/10;
	e=(x-a*10000-b*1000-c*100)%10;
	printf("%d   %d   %d   %d   %d\n",a,b,c,d,e);
	return 0;
}
