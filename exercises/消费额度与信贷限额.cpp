#include <stdio.h>
int main(){
	int accountNumber;
	double balance;
	double charges;
	double credits;
	double limit;
	
	printf("\nEnter account number(-1 to end)");/*�˺�*/ 
	scanf("%d",&accountNumber);
	
	while(accountNumber!=-1){
		printf("Enter beginning balance:");/*�³����*/ 
		scanf("%lf",&balance);
		
		printf("Enter total charges:");/*��֧������Ŀ*/ 
		scanf("%lf",&charges);
		
		printf("Enter total credits:");/*���ύ��͸֧*/ 
		scanf("%lf",&credits);
		
		printf("Enter credit limit:");/*�Ŵ��޶�*/ 
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
