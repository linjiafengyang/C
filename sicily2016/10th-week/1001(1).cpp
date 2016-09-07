#include <iostream>
using namespace std;
class Person {
    private:
        string name;
        string address;
        string phoneNumber;
        string email;
    public:
        virtual string toString() {
            return "Person";
        }
};
class Student: public Person {
    enum class_status {frssman, sophomore, junior, senior};
    class_status status;
    public:
        string toString() {
            return "Student";
        }
};
class Employee: public Person {
    
    string office;
    int salary;
public:
    virtual string toString() {
        return "Employee";
    }
};
class Faculty: public Employee {
private:    
    string officeHours;
    int  rank;
public:
    string toString() {
        return "Faculty";
    }
};
class Staff: public Employee {
private:    
    string title;
public:
    string toString() {
        return "Staff";
    }
};
class MyDate {
    int year;
    int month;
    int day;
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
