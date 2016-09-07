#include <iostream>
#include <cstring>
using namespace std;
class runtime_error {
public:
	runtime_error() {
		message = "Binary number format error";
	}
    string what() {
        return message;
    }
private:
	string message;
};
int parseBinary(const char * const binaryString) {
    char binarystring[1000];
    strcpy(binarystring, binaryString);
    int i;
    int num = 0;
    for (i = 0; i < strlen(binaryString); i++) {
        if (binaryString[i] <= '1' && binaryString[i] >= '0') {
            num = num * 2 + (binaryString[i] - 48);
        }
        else {
            throw runtime_error();
        }
    } 
    return num;
}
void f()
{
  try
  {
    cout << parseBinary("10001") << endl;
    cout << parseBinary("11111111") << endl;
    cout << parseBinary("21111111") << endl;
  }
  catch (runtime_error ex)
  {
    cout << ex.what() << endl;
  }
}
int main() {
	f();
}
