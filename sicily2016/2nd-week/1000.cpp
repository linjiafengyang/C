#include <iostream>
#include <cstring>
using namespace std;
class Student {
public:
	Student();
	Student(int a, char* b, int c);
	void set(int a, char* b , int c);
	void print();
private:
	int id;
	char name[50];
	int age;
};
Student::Student(int a, char* b = "No Name", int c = 0) {
	id = a;
	if(strcmp(b, "") == 0) {
		strcpy(name, "No Name");
	}
	else {
		strcpy(name, b);
	}
	age = c;
}
Student::Student() {
}
void Student::set(int a, char* b, int c) {
	id = a;
	strcpy(name, b);
	age = c;
}
void Student::print() {
	cout << name << " " << "(" << id << ")" << " is " << age << " years old." << endl; 
}
int main() {

  Student std1, std2(123, "John Smith", 19), std3(124);

  std1.set(100, "Bill Gates", 55);

  std1.print();

  std2.print();

  std3.print();

  return 0;

}
