#include <iostream>
#include <set>
using namespace std;
int getFriendNumber(int num) {
	int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}
int main() {
	set<int> s;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(getFriendNumber(num));
	}
	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (it != s.begin()) cout << " ";
		cout << *it;
	}
	return 0;
}