#include <iostream>
#include <string>
using namespace std;
string sort(string &s);
int main() {
	string s1("bca"), s2;
	s2 = sort(s1);
	cout << s2;
}
string sort(string &s) {
	int i, j;
	char temp;
	for(i = 0; i < s.size() - 1; i++) {
		for(j = 0; j < s.size() - i - 1; j++) {
			if(s[j] > s[j + 1]) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	return s;
}
