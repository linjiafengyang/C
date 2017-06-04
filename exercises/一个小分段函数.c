#include <stdio.h>
#include <math.h>
int main(){
	float x;
	scanf("%f",&x);
	if(x<-1){
		printf("%.2f\n",x+1);
	}
	if(-1<=x&&x<1){               /*×¢ÒâÃ»ÓÐ-1<=x<1*/ 
		printf("%.2f\n",fabs(x));
	}
	if(x>=1){
		printf("%.2f\n",log10(x));
	}
	return 0;
}
