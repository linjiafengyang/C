#include <stdio.h>
int main() {
	long long N,x,i;
	double Ex,Dx,Fx2;
	Ex=0;
	Fx2=0;
	scanf("%lld", &N);
	for(i=1;i<=N;i++) {
		scanf("%lld", &x);
		Ex=Ex+(double)x/N;
		Fx2=Fx2+(double)x*x/N;
	}
	Dx=Fx2-Ex*Ex;
	printf("%.2lf %.2lf\n", Ex, Dx);
	return 0;
}

