#include <iostream>
#include <iomanip>
#define leftform "left :"<<left<<setprecision(2)<<fixed 
#define rightform "right:"<<right<<setprecision(2)<<fixed 
using namespace std;
class Book
{
 string name;
 string code;
 double cost;
public:
 Book(string s,string c,double co):name(s),code(c),cost(co){}
 string getname() {
    return name;
 }
 string getcode() {
    return code;
 }
 double getcost() {
    return cost;
 }
};
ostream& operator<<(ostream& out, Book &a) {
    if (cout.precision() != 2) {
        cout << setprecision(6) << fixed;
    }
    out << setw(15) << a.getname()
		<< setw(15) << a.getcode() 
		<< setw(15) << setiosflags(ios::showpoint) 
		<< a.getcost() << endl;
}     
int main() {
    int N;
    string name;
    string code;
    double cost;
    cin >> N;
    int i = 0;
    Book *books[N];
     for(i=0;i<N;i++){
        cin >> name >> code >> cost;
        books[i] = new Book(name, code, cost);
    }
    for(i=0;i<N;i++){
        cout << "-----:" << *books[i];
    }
    for(i=0;i<N;i++){
        cout << leftform << *books[i];
    }
    for(i=0;i<N;i++){
        cout << rightform << *books[i];
    }
}
