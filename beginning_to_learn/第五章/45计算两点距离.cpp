#include <stdio.h>
#include <math.h>
double distance(double x1, double y1, double x2, double y2);
int main () {
	double x1, x2, y1, y2;
	double dist;
	printf("Enter the first point: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter the second point: ");
	scanf("%lf%lf", &x2, &y2);
	dist = distance(x1, y1, x2, y2);
	printf("Distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, dist);
	return 0;
}
double distance(double x1, double y1, double x2, double y2) {
	double distance;
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance;
}
