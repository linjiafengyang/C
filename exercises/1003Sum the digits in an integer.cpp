#include <stdio.h>
int main(){
	int x;
	int a;
	int b;
	int c;
	int d;
	scanf("%d",&x);
	a=x%10;
	b=x/100;
	c=x%100;
	d=(c-a)/10;
	printf("%d\n\n\n",a+b+d);
	printf("Now with another answer:\n");
	a=x/100;
	b=(x-a*100)/10;
	c=(x-a*100)%10; 
	printf("%d\n",a+b+c);
	return 0;
}
