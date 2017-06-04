#include <iostream>
#include <list>
using namespace std;
list<int> a[11];
void found(int value) {
	int temp = value % 11;
	list<int>::iterator iter;
	int count = 0;
	int flag = 0;
	for (iter = a[temp].begin(); iter != a[temp].end(); iter++) {
		if (*iter == value) {
			cout << count << endl;
			flag = 1;
			break;
		}
		count++;
	}
	if (!flag) cout << -1 << endl;
}
void my_hash(int value) {
	int temp = value % 11;
	a[temp].insert(a[temp].begin(), value);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char operation;
		cin >> operation;
		int value;
		cin >> value;
		if (operation == 'F') found(value);
		else my_hash(value);
	}
	return 0;
}