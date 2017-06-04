#include <stdio.h>
int main(){
	float mark,point;
	scanf("%f",&mark);
	point=(mark-50)/10;
	if(mark>100||mark!=(int)mark||mark<0){                  //注意56.0=56，即56.0可理解为整数；另外因为是分数，不超过100和少于0 
		printf("Invalid\n");
	}
	else{
		if(mark<=59){
			printf("Failed\n");
		}
		else{
			printf("%.1f\n",point);
		}
	}
	
	return 0;
}
  