#include <stdio.h>
int main(){
	double principal;/*本金*/ 
	double rate;/*利率*/ 
	double interest;/*利息*/ 
	int term;
	
	printf("Enter loan principal(-1 to end):");
	scanf("%lf",&principal);
	
	while(principal!=-1.0){
		printf("Enter interest rate:");
		scanf("%lf",&rate);
		
		printf("Enter term of the loan in days:");
		scanf("%d",&term);
		
		interest=principal*rate*term/365.0;
		printf("The interest charge is $%.2f\n\n",interest);
		
		printf("Enter loan principal(-1 to end):");
		scanf("%lf",&principal);
	}
	return 0;
} 
