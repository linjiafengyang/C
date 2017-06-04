#include <stdio.h>
int main(){
	float value;
	int a,b;
	int counter;
	counter=1;
	value=0;
	scanf("%d%d",&a,&b);
	while(counter<=6){
		value =(a+value)*(1+b*0.01/12);
		counter++;
	}
	printf("%.2f\n",value);
	return 0;
}
