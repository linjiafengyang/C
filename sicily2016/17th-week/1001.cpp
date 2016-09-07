#include <iostream>
#include <set>
using namespace std;
int sumOfIntersection(const set<int>& set1, const set<int>& set2) {
    int sum = 0;
    set<int>::iterator iter1;
    set<int>::iterator iter2;
    for (iter1 = set1.begin(); iter1 != set1.end(); iter1++) {
        for (iter2 = set2.begin(); iter2 != set2.end(); iter2++) {
            if (*iter1 == *iter2) {
                sum += *iter1;  
            }
        }
    }
    return sum;
}
