#include <stdio.h>
int main(){
	int a,b;
	int counter=0;
	scanf("%d",&a);
	while(counter<a){
		scanf("%d",&b);
		printf("%d\n",b);
		counter++;
	}
	return 0;
}
