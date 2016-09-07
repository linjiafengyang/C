#include <iostream>
#include <cstring>
using namespace std;
void f();
class String {
public:
    String();            // x = ""
    String(const char*);        // x = "abc" 
    String(const String&);    // x = other_string
    String& operator=(const char *);
    String& operator=(const String&);
    String operator+(String);
    char& operator[](int i);
    char operator[](int i) const;
    int size() const;
    String& operator+=(const String&);
    String& operator+=(const char*);
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
    friend bool operator==(const String& x, const char* s);
    friend bool operator==(const String& x, const String& y);
    friend bool operator!=(const String& x, const char* s);
    friend bool operator!=(const String& x, const String& y);
private:
	char a[10000];
};
String::String() {}
String::String(const char* x) {
    strcpy(a, x);
}
String::String(const String & b) {
    strcpy(a, b.a);
}
String& String::operator=(const char * b) {
    strcpy(a, b);
}
String& String::operator=(const String& b) {
    strcpy(a, b.a);
}
String String::operator+(String b) {
    String c;
    int i, j;
    for (i = 0; i < size(); i++) {
        c[i] = a[i];
    }
    for (j = 0; j <= b.size(); i++, j++) {
        c[i] = b[j];
    }
    return c;
}
char& String::operator[](int i) {
    return a[i];
}
char String::operator[](int i) const {
    return a[i];
}
int String::size() const {
    return strlen(a);
}
String& String::operator+=(const String& b) {
    int i, j;
    for (i = size(), j = 0; j < b.size(); i++, j++) {
        a[i] = b.a[j]; 
    }
}
String& String::operator+=(const char* b) {
    int i, j;
    for (i = size(), j = 0; j < strlen(b); i++, j++) {
        a[i] = b[j];
    }
}
ostream& operator<<(ostream& o, const String& b) {
    o <<  b.a;
    return o;
}
istream& operator>>(istream& i, String& b) {
    i >> b.a;
    return i;
}
bool operator==(const String& x, const char* s) {
    if (strcmp(x.a, s) == 0) {
        return true;
    }
    return false;
}
bool operator==(const String& x, const String& y) {
    if (strcmp(x.a, y.a) == 0) {
        return true; 
    } 
    return false;
}
bool operator!=(const String& x, const char* s) {
    if (strcmp(x.a, s) != 0) {
        return true;
    }
    return false;
}
bool operator!=(const String& x, const String& y) {
    if (strcmp(x.a, y.a) != 0) {
        return true; 
    } 
    return false;
}
int main() {
	f();
}
void f()
{
    String x, y, s;
    cout << "Please enter two strings\n";
    cin >> x >> y;
    cout << "x= " << x << " , y = " << y << '\n';

    cout << "s = \"" << s << "\"" << endl;
    s = "abc";
    cout << "s = \"" << s << "\"" << endl;

    cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
    String z = x;
    if (x != z) cout << "x corrupted!\n";
    x[0] = '!';
    if (x == z) cout << "write failed!\n";
    cout << "exit: " << x << ' ' << z << '\n';    

    z = s;
    if (s != z) cout << "s corrupted!\n";
    s[0] = '!';
    if (s == z) cout << "write failed!\n";
    cout << "exit: " << s << ' ' << z << '\n';    
}
