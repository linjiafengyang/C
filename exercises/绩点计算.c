#include <stdio.h>
int main(){
	float mark,point;
	scanf("%f",&mark);
	point=(mark-50)/10;
	if(mark>100||mark!=(int)mark||mark<0){                  //ע��56.0=56����56.0�����Ϊ������������Ϊ�Ƿ�����������100������0 
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
  