#include <iostream>
#include <vector>
using namespace std;
struct node {
	int cur, value, next;
};

vector<node> neg, small, big;
void split(node *nodes, int cur, int k) {
	while (cur != -1) {
		if (nodes[cur].value < 0) neg.push_back(nodes[cur]);
		else if (nodes[cur].value <= k) small.push_back(nodes[cur]);
		else big.push_back(nodes[cur]);

		cur = nodes[cur].next;
	}
}

vector<node> ans;
void merge() {
	ans = neg;
	for (int i = 0; i < small.size(); i++) {
		ans.push_back(small[i]);
	}
	for (int i = 0; i < big.size(); i++) {
		ans.push_back(big[i]);
	}
}

void printAns() {
	int i;
	for (i = 0; i < ans.size() - 1; i++) {
		printf("%05d %d %05d\n", ans[i].cur, ans[i].value, ans[i + 1].cur);
	}
	printf("%05d %d -1\n", ans[i].cur, ans[i].value);
}

int main() {
	int cur, n, k, temp;
	cin >> cur >> n >> k;
	node nodes[100000];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cin >> nodes[temp].value >> nodes[temp].next;
		nodes[temp].cur = temp;
	}
	split(nodes, cur, k);
	merge();
	printAns();
	return 0;
}