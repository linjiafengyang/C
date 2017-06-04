#include <stdio.h>
const double pi=3.14;
int main(){
	double area,perimeter,r;
	scanf("%lf",&r);
	area=pi*r*r;
	perimeter=2*pi*r;
	printf("%.2lf\n%.2lf\n",area,perimeter);
	return 0;
} 
