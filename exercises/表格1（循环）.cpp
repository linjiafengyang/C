#include <stdio.h>
int main(){
	int n=0;
	printf("\tN\t\t10*N\t\t100*N\t\t1000*N\n\n");
	while(++n<=10){
		printf("\t%-2d\t\t%-5d\t\t%-5d\t\t%-6d\n",n,10*n,100*n,1000*n);
	}
	return 0;
}
