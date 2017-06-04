#include <string.h>
#include <stdio.h>
int parseBinary1(const char * const binaryString);
int parseBinary2(const char * const binaryString);
int parseBinary3(const char * const binaryString);
int main() {
	const char s[6] = "10001";
	printf("%d", parseBinary1(s));
	printf(" %d", parseBinary2(s));
	printf(" %d", parseBinary3(s));
}
int parseBinary1(const char * const binaryString) {
  int decimal = binaryString[0] - '0';
  int i;
  for (i = 1; i < strlen(binaryString); i++)
  {
    decimal = decimal * 2 + binaryString[i] - '0';//从高位开始算 
  }
  return decimal;
}
int parseBinary2(const char * const binaryString) {
	int i = 0;
	int num = 0;
	int j = 0;
	int k;
	int time = 1;
	while(binaryString[i] != '\0') {
		i++;	//i = 5
	}
	int m = i - 1;
	for(i = m; i >= 0; i--, j++) {
		for(k = 0; k < j; k++) {
			time = time * 2;
		}
		num = num + (binaryString[i] - '0') * time;//从个位开始算 
		time = 1;
	}
	return num;
}
int parseBinary3(const char * const binaryString) {
	int decimal = binaryString[0] - '0';
	int i = 0;
	int m;
	while(binaryString[i] != '\0') {
		i++;
	}
	for(int j = 1; j < i; j++) {	//i = 5
		decimal = decimal * 2 + binaryString[j] - '0';//从高位开始算 
	}
	return decimal;
}
