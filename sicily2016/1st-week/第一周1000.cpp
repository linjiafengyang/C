#include <iostream>
#include <cstring>
using namespace std;
class Student {
public:
	int id;
	char name[50];
	int age;
	Student();
	Student(int a, char* b, int c);
};
void set(Student & a, int b, char* c , int d);
void print(Student a);
int main(){
	Student std1, std2(123, "John Smith", 18), std3(124, "", 0);
    set(std1, 100, "Bill Gates", 61);
    print(std1);
    print(std2);
    print(std3);
    return 0;
}

Student::Student(int a, char* b = "No Name", int c = 0) {
	id = a;
	if (strcmp(b, "") == 0) {
		strcpy(name, "No Name");
	}
	else {
		strcpy(name, b);
	}
	age = c;
}

Student::Student() {
}

void set(Student & a, int b, char* c, int d) {
	a.id = b;
	strcpy(a.name, c);
	a.age = d;
}
void print(Student a) {
	cout << a.name << " " << "(" << a.id << ")" << " is " << a.age << " years old." << endl;
}
