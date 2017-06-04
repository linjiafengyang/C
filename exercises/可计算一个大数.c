#include <stdio.h>
int main(){
	long long  a,b,c;        //直接long long（64位）即可，long不行 
	scanf("%lld%lld",&a,&b);    //%lld 或者 %I64d 
	c=a*b;
	printf("%lld\n",c);
	return 0;
}
