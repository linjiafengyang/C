#include <iostream>
#include <cstring>
using std::endl;
int myplus(int a, int b);
double myplus(double c, double d);
std::string myplus(std::string str1, std::string str2);
int main() {
	int n;
	int a, b;
	double c, d;
	std::string str1, str2;
	std::cin >> n;
	while(n--) {
		std::cin >> a >> b ;
		std::cin >> c >> d;
		std::cin >> str1 >> str2;
		std::cout << myplus(a, b) << endl;
		std::cout << myplus(d, c) << endl;
		std::cout << myplus(str1, str2) << endl;
	}
	return 0;
}
int myplus(int a, int b) {
	return a + b;
}
double myplus(double c, double d) {
	return c + d;
}
std::string myplus(std::string str1, std::string str2) {
	return str1 + str2;
}
