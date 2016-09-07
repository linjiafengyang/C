#include <iostream>
using namespace std;
class Sequence {
	public:
		Sequence();
		int size();
		bool empty();
		bool find(int value);
		int &at(int pos);
		int front();
		int back();
		void insert(int value);
		void insert(int pos, int value);
		void clear();
		void reverse();
		void reverse(int fir, int las);
		void replace(int value1, int value2);
		void swap(Sequence &seq2); 
		int *a;
		int _size;
		bool _empty;
};
Sequence::Sequence() {
	a = new int[1000];
	_size = 0;
	_empty = true;
}
int Sequence::size() {
	return _size;
}
bool Sequence::empty() {
	return _empty;
}
bool Sequence::find(int value) {
	int i;
	for (i = 0; i < _size; i++) {
		if (a[i] == value) {
			return true;
		}
	}
	return false;
}
int & Sequence::at(int pos) {
	return a[pos];
}
int Sequence::front() {
	return a[0];
}
int Sequence::back() {
	return a[_size - 1];
}
void Sequence::insert(int value) {
	a[_size] = value;
	_size++;
	_empty = false;
}
void Sequence::insert(int pos, int value) {
	int i;
	for (i = _size; i > pos; i--) {
		a[i] = a[i - 1];
	}
	a[pos] = value;
	_size++;
	_empty = false;
}
void Sequence::clear() {
	int i;
	delete []a;
	a = new int[1000];
	_size = 0;
	_empty = true;
}
void Sequence::reverse() {
	int i, temp;
	for(i = 0; i <= _size / 2 - 1; i++) {
		temp = a[i];
		a[i] = a[_size - 1 - i];
	a[_size - i - 1] = temp;
	}
}
void Sequence::reverse(int fir, int las) {
	int i, temp, j = 0;
	las--;
	for(i = fir; i < fir + (las + 1 - fir) / 2; i++) {
		temp = a[i];
		a[i] = a[las - j];
		a[las - j] = temp;
		j++;
	}
}
void Sequence::replace(int value1, int value2) {
	int i;
	for (i = 0; i < _size; i++) {
		if(a[i] == value1) {
			a[i] = value2;
		}
	}
}
void Sequence::swap(Sequence &seq2) {
	int i;
	int  *b;
	b = a;
	int temp = _size;
	bool temp2 = _empty;
	a = seq2.a;
	seq2.a = b;
	_size = seq2._size;
	_empty = seq2._empty;
	seq2._size = temp;
	seq2._empty = temp2;
}
int main() {
	Sequence seq, seq2;
	seq.insert(1);
	seq.insert(2);
	seq.insert(3);
	seq.insert(3);
	cout << seq._size << endl;
	seq2.insert(3);
	seq2.insert(4);
	seq2.insert(5); 
	cout << seq.empty() << endl;
	cout << seq.find(2) << endl;
	cout << seq.at(2) << endl;
	cout << seq.front() <<endl;
	cout << seq.back()<<endl;
	seq.insert(2, 4);
	seq2.reverse();
	seq.reverse(1, 2);
	for(int i = 0; i < 4; i++) {
		cout << seq.a[i] << " ";
	}
	cout << endl;
	seq.replace(3, 5);
	for (int i = 0; i < 4; i++) {
		cout << seq.a[i] << " ";
	}
	cout << endl;
	seq.swap(seq2);
	for(int i = 0; i < 3; i++) {
		cout << seq.a[i] <<" ";
	}
}
