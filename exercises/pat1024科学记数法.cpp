#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int stringToInt(const string& S) {
	stringstream ss;
	int result;
	ss << S;
	ss >> result;
	return result;
}

int main() {
	string str, num;
	int exp;
	cin >> str;
	char sign = str[0];
	int LocE = str.find('E');
	num = str[1];
	num += str.substr(3, LocE - 3);
	exp = stringToInt(str.substr(LocE + 1));
	if (sign == '-') {
		cout << "-";
	}
	if (exp < 0) {
		cout << "0.";
		for (int i = 0; i < -exp - 1; i++) {
			cout << '0';
		}
		cout << num;
	}
	else if (exp >= num.length() - 1) {
		cout << num;
		for (int i = 0; i < exp - num.length() + 1; i++) {
			cout << '0';
		}
	}
	else {
		cout << num.substr(0, exp + 1);
		cout << ".";
		cout << num.substr(exp + 1);
	}
}