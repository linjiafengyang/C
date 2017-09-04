#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int result = 0;
	int countP = 0;
	int countT = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'T') countT++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'T') countT--;
		if (s[i] == 'P') countP++;
		if (s[i] == 'A') {
			result = (result + (countP * countT)) % 1000000007;
		}
	}
	cout << result;
	return 0;
}