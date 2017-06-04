#include <stdio.h>
int main() {
	int A,B;
	int i;
	scanf("%d%d", &A, &B);
	for(i=A;i<=B;i++) {
		if(i%2==1){
			printf("%d\n",i);
		}
	}
	return 0;
}

