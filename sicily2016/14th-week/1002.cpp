#include <iostream>
using namespace std;
template < typename T >
T maxValue (const T value1, const T value2) {
	T temp1 = value1;
	T temp2 = value2;
	if(value2 >= 'A' && value2 <= 'Z') {
		if(value1 >= 'a' && value1 <= 'z') {
			temp1 -= 32;
		}
		if(temp1 == temp2) {
			return temp2;
		}
		return temp1 > temp2 ? value1 : value2;
	}
	if(value1 >= 'A' && value1 <= 'Z') {
		if(value2 >= 'a' && value2 <= 'z') {
			temp2 -= 32;
		}
		if(temp1 == temp2) {
			return temp1;
		}
		return temp1 > temp2 ? value1 : value2;
	}
	return temp1 > temp2 ? value1 : value2;
}
string maxValue(const string value1, const string value2) {
	return value1 > value2 ? value1 : value2;
}
int main(int argc, char** argv) {
	int a = 3, b = 2;
	char c = 'B', d = 'b';
	string e = "name", f = "school";
	cout << maxValue(a, b) << endl;
	cout << maxValue(c, d) << endl;
	cout << maxValue(e, f) << endl;
	return 0;
}
