#include <iostream>
#include <algorithm>
using namespace std;
template<typename T>
class SortableArray{
private:
    int size;
    int maxArraysize;
    T *data;
public:
    SortableArray(int max) {
        size = 0;
        maxArraysize = max;
        data = new T[max];
    } 
    bool pushBack(T a) {
        if (size + 1 > maxArraysize) {
            return false;
        }
        else {
            data[size++] = a;
            return true;
        }
    }
    void sort() {
        std::sort(data, data + size);
    }
    void printArray() {
        int i;
        for (i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main() {
	int maxSize = 10;
	SortableArray<int> arr(maxSize);
	arr.pushBack(45);
	arr.pushBack(32);
	arr.pushBack(41);
	arr.printArray();
	arr.sort();
	arr.printArray();
}
