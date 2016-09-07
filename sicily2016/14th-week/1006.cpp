#include <iostream>
using namespace std;
template<typename T>
void swapVar(T& var1, T& var2) {
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}
int main(int argc, char** argv) {
	int a = 1, b = 2;
	double c = 1.8, d = 3.8;
	string e = "name", f = "school";
	swapVar(a, b);
	cout << a << " " << b << endl;
	swapVar(c, d);
	cout << c << " " << d << endl;
	swapVar(e, f);
	cout << e << " " << f << endl;
	return 0;
}
