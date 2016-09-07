#include <iostream>
int* doubleCapacity(int *list, int size);
using namespace std;
int main(int argc, char** argv) {
	int list[5] = {1, 2, 3, 4, 5};
	int *newlist = doubleCapacity(list, 5);
	for(int i = 0; i < 2 * 5; i++) {
		cout << *(newlist + i) << " ";
	}
	return 0;
}
int* doubleCapacity(int *list, int size){
    int *p;
    int i;
    p = new int[2 * size];
    for(i = 0; i < size; i++){
        *(p + i) = *(list + i);
    }
    for(; i < 2 * size; i++){
        *(p + i) = 0;
    }
    return p;
}                                 
