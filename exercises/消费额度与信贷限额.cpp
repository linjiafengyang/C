#include <stdio.h>
int main(){
	int accountNumber;
	double balance;
	double charges;
	double credits;
	double limit;
	
	printf("\nEnter account number(-1 to end)");/*账号*/ 
	scanf("%d",&accountNumber);
	
	while(accountNumber!=-1){
		printf("Enter beginning balance:");/*月初余额*/ 
		scanf("%lf",&balance);
		
		printf("Enter total charges:");/*已支付的项目*/ 
		scanf("%lf",&charges);
		
		printf("Enter total credits:");/*已提交的透支*/ 
		scanf("%lf",&credits);
		
		printf("Enter credit limit:");/*信贷限额*/ 
		scanf("%lf",&limit);
		
		balance+=charges-credits;
		
		if(balance>limit){
			printf("%s%d\n%s%.2f\n%s%.2f\n%s\n",
			       "Account:    ",accountNumber,"Credit limit:",limit,
				   "Balance:    ",balance,"Cresit Limit Exceeded.");
		}
		
		printf("\nEnter account number(-1 to end):");
		scanf("%d",&accountNumber);
	}
	return 0;
}
