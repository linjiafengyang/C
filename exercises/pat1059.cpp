#include <iostream>
#include <set>
#include <cmath>
using namespace std;
bool isprime(int a) {
	if (a <= 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) return false;
	}
	return true;
}
int main() {
	int n, k;
	cin >> n;
	int rank[10000];
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		rank[id] = i + 1;
	}
	cin >> k;
	set<int> ss;
	for (int i = 0; i < k; i++) {
		int id;
		cin >> id;
		printf("%04d: ", id);
		if (rank[id] == 0) {
			cout << "Are you kidding?" << endl;
			continue;
		}
		if (ss.find(id) == ss.end()) {
			ss.insert(id);
		}
		else {
			cout << "Checked" << endl;
			continue;
		}
		if (rank[id] == 1) {
			cout << "Mystery Award" << endl;
		}
		else if (isprime(rank[id])) {
			cout << "Minion" << endl;
		}
		else {
			cout << "Chocolate" << endl;
		}
	}
	return 0;
}
