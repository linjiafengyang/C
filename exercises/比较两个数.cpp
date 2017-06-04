#include <stdio.h>
int main(){
	int x,y;
	printf("Please enter two numbers:");
	scanf("%d%d",&x,&y);
	if(x>y){
		printf("%d is larger\n",x);
	}
	if(x<y){
		printf("%d is larger\n",y);
	}
	if(x==y){
		printf("These numbers are equal\n");
	}
	return 0;
}
