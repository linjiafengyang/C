#include <stdio.h>
#include <math.h>
int main() {
    int investmentAmount, numberOfYear;
    float b, accumulatedValue, monthlyInterestRate;
    scanf("%d%f%d", &investmentAmount, &b, &numberOfYear);
    monthlyInterestRate = b * 0.01 / 12;
    accumulatedValue = investmentAmount * pow((1 + monthlyInterestRate), (numberOfYear*12));
    printf("%.2f\n", accumulatedValue);
    return 0;
}
