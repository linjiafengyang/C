#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um;
        for (auto e : employees) {
        	um[e->id] = e;
        }
        return getSum(um, id);
    }
private:
	int getSum(unordered_map<int, Employee*>& um, int id) {
		int ans = um[id]->importance;
		for (auto e : um[id]->subordinates) {
			ans += getSum(um, e);
		}
		return ans;
	}
};
int main() {
	int n, num;
	cout << "Please input the number of Employees:";
	cin >> n;
	vector<Employee*> ems;
	Employee em[n];
	for (int i = 0; i < n; i++) {
		cin >> em[i].id >> em[i].importance;
		cout << "Please input the number of direct Employees:";
		cin >> num;
		int temp;
		for (int j = 0; j < num; j++) {		
			cin >> temp;
			em[i].subordinates.push_back(temp);
		}
		ems.push_back(&em[i]);
	}

	// cout << ems.size() << endl;
	// for (int i = 0; i < ems.size(); i++) {
	// 	cout << ems[i]->id << " " << ems[i]->importance << endl;
	// }

	int idNum;
	cin >> idNum;
	Solution s;
	cout << s.getImportance(ems, idNum) << endl;
	return 0;
}
/*
input:
Please input the number of Employees:3
1
5
Please input the number of direct Employees:2
2 3

2
3
Please input the number of direct Employees:0

3
3
Please input the number of Employees:0

1

output:
11
 */