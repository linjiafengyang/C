#include <stdio.h>
int main(){
	const float fahrenheit=72.0;
	float celsius;
	celsius = (fahrenheit- 32) * (5.0 / 9.0);/*ע�����Ҫ5.0��9.0���Ѿ����ӹ���*/ 
	printf("%.4f",celsius);
	return 0;
}
