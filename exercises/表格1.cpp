#include<stdio.h>
int main(){
    int n;
    n=0;
    printf("\t+-------+-------+-------+------+\n");
    printf("\t|N\t|10*N\t|100*N\t|1000*N|\n");
    while(++n<=10){
    	printf("\t+-------+-------+-------+------+\n"); 
    	printf("\t|%-2d\t|%-5d\t|%-5d\t|%-6d|\n",n,10*n,100*n,1000*n);
    }
    printf("\t+-------+-------+-------+------+\n");
    return 0;
}
	 
