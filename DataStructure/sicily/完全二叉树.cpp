#include <iostream>
using namespace std;
int com(int x, int y) {
	if (x == y) return x;
	else if (x > y) com(x / 2, y);
	else return com(x, y / 2);
}
int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << com(a, b) << endl;
	return 0;
}