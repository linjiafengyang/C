#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class  runtime_error{
public:
	runtime_error() {
		message = "Hex number format error";
	}
    string what() {
        return message;
    }
private:
	string message;
};
int parseHex(const char * const hexString) {
    int i;
    char hexstring[10000];
    strcpy(hexstring, hexString);
    for (i = 0; i < strlen(hexString); i++) {
        if (hexString[i] > 'F' || (hexString[i] > '9' && hexString[i] < 'A') || hexString[i] < '0') {
            break;
        }
    }
    if (i < strlen(hexString)) {
        throw runtime_error();
    }
    else {
        int z = strlen(hexString) - 1;
        int k = 0;
        for (i = 0; i < strlen(hexString); i++) {
            if (hexString[i] >= 'A' && hexString[i] <= 'Z') {
                hexstring[i] -= 7;
            }
            k += (hexstring[i] - 48) * pow(16, z--);
        }
        return k;
    }
}
void f()
{
  try
  {
    cout << parseHex("10") << endl;
    cout << parseHex("ABC") << endl;
    cout << parseHex("9G3") << endl;
  }
  catch (runtime_error ex)
  {
    cout << ex.what() << endl;
  }
}
int main() {
	f();
}
