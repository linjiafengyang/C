#include <iostream>
using namespace std;
int main() {
	char s[100];
	cin.getline(s, 100);
	int i;
	int temp = 0;
	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] == ' ') {
			temp = 0;
		}
		else if(temp == 0) {
			temp = 1;
			if(s[i] >= 'a' && s[i] <= 'z') {
				s[i] = s[i] - 32;
			}
		}
	}
	cout << s;
}
