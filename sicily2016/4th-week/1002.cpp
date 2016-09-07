#include <iostream>
using namespace std;
char * convertDecimalToHex(int value);
void convertDecimalToHex(int value, char *s);
int main() {
	int value;
	cin >> value;
	char *news = convertDecimalToHex(value);
	char *s = new char[10];//须初始化 
	cout << news << endl;
	convertDecimalToHex(value, s);
	cout << s;//在main（）函数中输出，不然过不了sicily 
	return 0;
}
char * convertDecimalToHex(int value) {
	char *p = new char[10];
	int i, j;
	if(value == 0) {//考虑0的情况 
		p[0] = 0 + '0';
		p[1] = '\0';//注意是字符串，后面得用\0 
	}
	else {
		for(i = 0; value != 0; i++) {//注意顺序是颠倒的 
			if(value % 16 > 9) {
				p[i] = value % 16 - 10 + 'A';
			}
			else {
				p[i] = value % 16 + '0';
			}
			value = value / 16;
		}
		p[i] = '\0';//注意\0 
		i = i - 1;
		for(j = 0; j < i; j++, i--) {//颠倒顺序 
			char temp;
			temp = p[j];
			p[j] = p[i];
			p[i] = temp;
		}		
	}
	return p;
}
void convertDecimalToHex(int value, char *s) {
	int i, j;
	if(value == 0) {
		s[0] = 0 + '0';
		s[1] = '\0';
	}
	else {
		for(i = 0; value != 0; i++) {
			if(value % 16 > 9) {
				s[i] = value % 16 - 10 + 'A';
			}
			else {
				s[i] = value % 16 + '0';
			}
			value = value / 16;
		}
		s[i] = '\0';
		i = i - 1;
		for(j = 0; j < i; j++, i--) {
			char temp;
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;
		}
	}
}
