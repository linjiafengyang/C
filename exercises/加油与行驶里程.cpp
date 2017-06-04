#include <stdio.h>
int main(){
	double gallons;
	double miles;
	double totalGallons=0.0;
	double totalMiles=0.0;
	double totalAverage;
	
	printf("Enter the gallons used(-1 to end):");
	scanf("%lf",&gallons);
	
	while(gallons!=-1.0){
		totalGallons+=gallons;
		
		printf("Enter the miles driven:");
		scanf("%lf",&miles);
		totalMiles+=miles;
		printf("The Miles/Gallon for this tank was %f\n\n",miles/gallons);
		
		printf("Enter the gallons used(-1 to end):");
		scanf("%lf",&gallons);
	}
	totalAverage=totalMiles/totalGallons;
	printf("\nThe overall average Miles/Gallon was %f\n",totalAverage);
	return 0;
} 
