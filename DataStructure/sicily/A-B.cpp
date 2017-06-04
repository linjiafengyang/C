#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	set<int> s;
	while (t--) {
		int num;
		cin >> num;
		int a;
		while (num--) {
			cin >> a;
			s.insert(a);
		}
		cin >> num;
		while (num--) {
			cin >> a;
			s.erase(a);
		}
		for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
			if (iter == s.begin()) {
				cout << *iter;
			}
			else {
				cout << " " << *iter;
			}
		}
		s.clear();
		cout << endl;
	}
	return 0;
}