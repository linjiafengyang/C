#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		s[i] = tolower(s[i]);
	}
	int a[26] = {0};
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			a[s[i] - 'a']++;
		}
	}
	int max = a[0];
	int t = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > max) {
			max = a[i];
			t = i;
		}
	}
	char temp = t + 'a';
	cout << temp << " " << max;
	return 0;
}