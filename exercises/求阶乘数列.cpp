#include <stdio.h>
int main(){
	double sum  = 0.0;
	int i, j;
	for(i = 1; i <= 30; i++){
		double sum1 = 1.0;
		for(j = 1; j <= i; j++){
			sum1 *= j;
		}
		sum += sum1;
	}
	printf("%.2e", sum);
}
