#include <stdio.h>
int main(){
	int a1,b1;
	int a2,b2;
	int a,b,c;
	scanf("%d%d",&a1,&b1);
	scanf("%d%d",&a2,&b2);
    a=a1*a2;
	b=a1*b2+a2*b1;
	c=b1*b2;
	printf("%dx^2+%dx+%d\n",a,b,c);
	return 0;
}
