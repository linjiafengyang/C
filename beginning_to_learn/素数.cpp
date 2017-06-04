#include <stdio.h>
#include <math.h>
int main() {
	unsigned int P;
	int a;
	int i;
	scanf("%u", &P);
	a=(int)sqrt(P);
	if(P>1&&P<=100000){     //1²»ÊÇËØÊý 
		for(i=2;i<=a;i++) {
			if(P%i==0) {
				break;
			}
		}
		if(i>a) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	else {
		printf("No\n");
	} 
	return 0;
}

