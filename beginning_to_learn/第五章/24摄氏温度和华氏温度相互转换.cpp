#include <stdio.h>
int celcius(int fTemp);
int fahrenheit(int cTemp);
int main() {
	int i;
	printf("Fahrenheit equivalents of Celcius temperatures:\n");
	printf("Celcius\t\tFahrenheit\n");
	for(i = 0; i <= 100; i++) {
		printf("%d\t\t%d\n", i, fahrenheit(i));
	}
	printf("\nCelcius equivalents of Fahrenheit temperatures:\n");
	printf("Fahrenheit\tCelcius\n");
	for(i = 32; i <= 212; i++) {
		printf("%d\t\t%d\n", i, celcius(i));
	}
	return 0;
}
int celcius(int fTemp) {
	return (int)(5.0 / 9.0 * (fTemp - 32));
}
int fahrenheit(int cTemp) {
	return (int)(9.0 / 5.0 * cTemp + 32);
}
