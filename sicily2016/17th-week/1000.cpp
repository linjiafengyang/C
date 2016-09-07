#include <iostream>
using namespace std;
template<typename T>
class Set
{
public:
    Set(){
        count = 0;
    } 
    Set(int maxsize) {
        count = 0;
        maxSize = maxsize;
        data = new T[maxSize];
    }
    ~Set(){
        delete []data;
    }
    Set(const Set& a) {
        count = a.getCount();
        maxSize = a.getMaxSize();
        data = new T[maxSize];
        int i;
        for (i = 0; i < count; i++) {
            data[i] = a.getData()[i];
        }
    }
    Set operator+(const Set& s) {
        int i;
        Set temp(1000);
        for (i = 0; i < count; i++) {
            temp.insert(data[i]);
        }
        for (i = 0; i < s.getCount(); i++) {
            temp.insert(s.getData()[i]);
        }
        return temp;
    }
    Set operator-(const Set& s) {
        int i;
        Set temp(1000);
        for (i = 0; i < count; i++) {
            temp.insert(data[i]);
        }
        for (i = 0; i < s.getCount(); i++) {
            temp.erase(s.getData()[i]);
        }
        return temp;
    }
    void operator=( const Set& s) {
        int i;
        data = new T[s.getMaxSize()];
        for (i = 0; i < s.getCount(); i++) {
            data[i] = s.getData()[i];
        }
        count = s.getCount();
    }
    bool insert(T newItem) {
        for (int i = 0; i < count; i++) {
            if (data[i] == newItem) {
                return false;
            }
        }
        if (count + 1 <= maxSize) {
            data[count++] = newItem;
            return true;
        }
    }
    bool erase(T targetItem) {
        int i;
        for (i = 0; i < count; i++) {
            if (data[i] == targetItem) {
                for (int j = i; j < count; j++) {
                    data[j] = data[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }
    void print() const {
        int i;
        for (i = 0; i < count - 1; i++) {
            cout << data[i] << " ";
        }
        cout << data[i] << " " << endl;
    }
    T* getData() const {
        return data;
    }
    int getCount() const {
        return count;
    }
    int getMaxSize() const {
        return maxSize;
    }
private:
    int count;
    int maxSize;
    T* data;
};
int main() {
	Set<int> s1(10), s2(10), s_plus, s_minus;
	s1.insert(1);
	s1.insert(2);
	s1.insert(2);
	s1.insert(4);
	cout << "Items in s1 are : ";
	s1.print();
	
	s2.insert(3);
	s2.insert(3);
	s2.insert(1);
	s2.insert(2);
	cout << "Items in s2 are: ";
	s2.print();

	s_plus = s1 + s2;
	cout << "Items in s_plus are: ";
	s_plus.print();
	
	s_minus = s1 - s2;
	cout << "Items in s_minus are: ";
	s_minus.print();
}                              
