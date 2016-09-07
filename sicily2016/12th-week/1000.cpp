#include <iostream>
using namespace std;
class base
{
char *name;
int age;
public:
base(){}
void setname(char arr[]) {
    name = arr;
}
void setage(int age1) {
    age = age1;
}
char* getname() {
    return name;
}
int getage() {
    return age;
}
};
class leader:public base {
    char *job;
    char *dep;
public:
    leader(){
    }
    void setjob(char arr[]) {
        job = arr;
    }
    void setdep(char arr[]) {
        dep = arr;
    }
    char* getjob() {
        return job;
    }
    char* getdep() {
        return dep;
    }
};
class engineer:public base {
    char *major;
    char *prof;
public:
    engineer(){
    }
    void setmajor(char arr[]) {
        major = arr;
    }
    void setprof(char arr[]) {
        prof = arr;
    }
    char* getmajor() {
        return major;
    }
    char* getprof() {
        return prof;
    }   
};
class chairman:public leader, public engineer {
char *name;
int age;
public:
chairman(){}
void setname(char arr[]) {
    name = arr;
}
void setage(int age1) {
    age = age1;
}
char* getname() {
    return name;
}
int getage() {
    return age;
}
};
int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
int n;
cin>>n;
for (int i=0;i<n;i++)
{
char name[20],job[20],dep[20],major[20],prof[20];
            int age;
cin>>name>>age>>job>>dep>>major>>prof;
chairman man;
man.setname(name);
man.setage(age);
man.setjob(job);
man.setdep(dep);
man.setmajor(major);
man.setprof(prof);
 
cout<<"name: "<<man.getname()<<" age: "<<man.getage()<<" dep: "<<man.getdep()
<<" job: "<<man.getjob()<<endl;
cout<<"prof: "<<man.getprof()<<" major: "<<man.getmajor()<<endl;
}
return 0;
}
