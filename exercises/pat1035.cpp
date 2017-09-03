#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> origin(n), target(n);
    for (int i = 0; i < n; i++) {
        cin >> origin[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }
    // 插入排序的特征：前面为有序的，后面与原始序列一样
    // 如果不是插入排序，则是归并排序
    int index = -1;
    for (int i = 1; i < n; i++) {
        if (target[i] < target[i - 1]) {
            index = i;
            break;
        }
    }
    int flag = 0; // 0为插入排序，1为归并排序
    for (int i = index; i < n; i++) {
        if (target[i] != origin[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "Insertion Sort" << endl;
        // 输出下一步
        sort(target.begin(), target.begin() + index + 1);
        cout << target[0];
        for (int i = 1; i < n; i++) {
            cout << " " << target[i];
        }
    }
    else if (flag == 1) {
        cout << "Merge Sort" << endl;
        // 输出下一步
        int k = 1;
        bool isNotEqual = true;
        while (isNotEqual) {
            isNotEqual = false;
            if (!equal(origin.begin(), origin.end(), target.begin())) {
                isNotEqual = true;
            }
            k *= 2;
            for (int i = 0; i < n / k; ++i) {
                sort(origin.begin() + i * k, origin.begin() + (i + 1) * k);
            }
            // 将剩下的排序
            sort(origin.begin() + k * (n / k), origin.end());
        }
        cout << origin[0];
        for (int i = 1; i < n; i++) {
            cout << " " << origin[i];
        }
    }
    cout << endl;
    return 0;
}