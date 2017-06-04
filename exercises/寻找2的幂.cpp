#include <stdio.h>
int main(){
	double a=2,i=1;
	while(a<=1000){
	    a=a*2;
	    i=i+1;
    }
	printf("%.lf\n%.lf\n",a,i);
	return 0;
}
