#include <stdio.h>
int main(){
	char  a;
    int b;
	double c,d,e,f;
	scanf("%c %d %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
	printf("%c %d %.2lf %.0lf %.0lf %.7lf\n",a,b,c,d,e,f);
	return 0;	
}
