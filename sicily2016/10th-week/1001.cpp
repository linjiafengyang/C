#include <iostream>
using namespace std;
class MyDate {
	private:
    	int year;
    	int month;
    	int day;
    public:
    	MyDate() {
		}
		MyDate(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		}
};
class Person {
    private:
        string name;
        string address;
        string phoneNumber;
        string email;
    public:
    	Person() {
		}
		Person(string name1, string address1, string phoneNumber1, string email1) {
			name = name1;
			address = address1;
			phoneNumber = phoneNumber1;
			email = email1;
		}
        virtual string toString() {
            return "Person";
        }
};
class Student: public Person {
	private:
    	enum class_status {frssman, sophomore, junior, senior};
    	class_status status;
    public:
    	Student() {
		}
        string toString() {
            return "Student";
        }
};
class Employee: public Person {
	public:
		MyDate dateHired;
    	string office;
    	int salary;
	public:
		Employee() {
		}
		Employee(string a, int b, MyDate& c) {
			office = a;
			salary = b;
			dateHired = c;
		}
    	virtual string toString() {
        	return "Employee";
    	}
};
class Faculty: public Employee {
private:    
    string officeHours;
    int rank;
public:
	Faculty(){
	}
	Faculty(string a, int b) {
		officeHours = a;
		rank = b;
	}
    string toString() {
        return "Faculty";
    }
};
class Staff: public Employee {
private:    
    string title;
public:
	Staff() {
	}
	Staff(string a) {
		title = a;
	}
    string toString() {
        return "Staff";
    }
};
void f(Person &p)
  {
    cout << p.toString() << endl;
  }
int main() {
  Person person;
  Student student;
  Employee employee;
  Faculty faculty;
  Staff staff;
  f(person);
  f(student);
  f(employee);
  f(faculty);
  f(staff);
}
