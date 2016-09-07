#include <iostream>
using namespace std;
class TypeA
{
public:
  class SubType
  {
  public:
    string toString() {return "subType in TypeA";};
  };
};

class TypeB
{
public:
  class SubType
  {
  public:
    string toString() {return "subType in TypeB";};
  };
};
template <typename T>
class MyClass
{
public:
    typename T::SubType subtypeobj;
};
int main(int argc, char** argv) {
	MyClass<TypeA> obj1;
	cout << obj1.subtypeobj.toString() << endl;
	MyClass<TypeB> obj2;
	cout << obj2.subtypeobj.toString() << endl;
	return 0;
}
