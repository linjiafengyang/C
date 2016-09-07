#include <iostream>
using namespace std;
class Object {
public:
    string n;
    Object() {
        n = (string)"Object";
    }
    
    virtual string name() {
        return n;
    } 
};
class Animal:public Object {
public:
    Animal() {
        n = (string)"Animal";
    }
    virtual string name() {
        return n;
    }   
};
class Dog:public Animal {
public:
    Dog() {
        n = "Dog";;
    }
    virtual string name() {
        return n;
    }   
};
class Cat:public Animal {
public:
    Cat() {
        n = "Cat";
    }
    
    virtual string name() {
        return n ;
    }   
};
 
class Vehicle:public Object {
public:
    Vehicle() {
        n = "Vehicle";
    }
    
    virtual string name() {
        return n;
    }   
};
class Bus:public Vehicle {
public:
    Bus() {
        n = "Bus";
    }
    
    virtual string name() {
        return n;
    }   
};
class Car:public Vehicle {
public:
    Car() {
        n = "Car";
    }
    
    virtual string name() {
        return n;
    }   
};
class Person:public Object {
public:
    Person() {
        n = "Person";
    }
    virtual string name() {
        return n;
    }   
};
class Student:public Animal { 
public:
    Student() {
        n = "Student";
    }
    
    virtual string name() {
        return n;
    }   
};
class Teacher:public Animal {
public:
    Teacher() {
        n = "Teacher";
    }
    virtual string name() {
        return n;
    }   
};
string instanceof(Object obj) {
    return obj.name();
}
int main() {
	Object *obj = new Dog();
	cout << instanceof(*obj) << endl;
	Object *obj1 = new Car();
	cout << instanceof(*obj1) << endl;
}
