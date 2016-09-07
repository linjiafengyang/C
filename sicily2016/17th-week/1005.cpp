#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
template<typename T>
bool cmp(T a, T b) { 
        if (a == b) {
            return true;
        } 
        return false;
} 
bool cmp(char* a, char *b) {
    char* t2;
    if (typeid(a).name() == typeid(t2).name()) {
        if (strcmp(a, b) == 0) {
            return true;
        } 
        return false;
    }
} 
bool cmp(int* a, int *b) {
        if (*a == *b) {
            return true;
        } 
        return false;
} 
bool cmp(double* a, double *b) {
        if (*a == *b) {
            return true;
        } 
        return false;
} 
bool cmp(float* a, float *b) {
        if (*a == *b) {
            return true;
        } 
        return false;
} 
bool cmp(string* a, string *b) {
        if (*a == *b) {
            return true;
        } 
        return false;
}
int main() {
	int aInt = 1, bInt = 2;
	double aDouble = 3.0, bDouble = 3.0;
	char aChars[5] = "haha", bChars[5];
	string aStr = "haha", bStr = "aha";
	int* aIntPtr = &aInt, *bIntPtr = &bInt;

	cout << boolalpha << cmp(aInt, bInt) << endl;
	cout << cmp(aDouble, bDouble) << endl;

	strcpy(bChars, aChars);
	cout << cmp(aChars, bChars) << endl;
	cout << cmp(aStr, bStr) << endl;
	cout << cmp(aIntPtr, bIntPtr) << endl;
}
