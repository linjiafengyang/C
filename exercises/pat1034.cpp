#include <iostream>
#include <cmath>
using namespace std;

// 求最大公约数的函数
long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(long a, long b) {
    long c = 0; // 带分数前面的整数部分，默认为0
    if (a > 0) { // 正数
        if (b == 1) { // 形如3/1
            cout << a;
        }
        else if (a > b) { // 形如5/3
            c = a / b;
            a -= b * c;
            cout << c << " " << a << "/" << b;
        }
        else { // 真分数 形如3/5
            cout << a << "/" << b;
        }
    }
    else if (a == 0) { // 形如0/3
        cout << '0';
    }
    else { // 负数
        if (b == 1) { // 形如-3/1
            cout << "(" << a << ")";
        }
        else if (-1 * a > b) { // 形如-5/3
            c = a / b;
            a = (-1 * a) % b;
            cout << "(" << c << " " << a << "/" << b << ")";
        }
        else { // 真分数
            cout << "(" << a << "/" << b << ")";
        }
    }
}
void add(long a1, long b1, long a2, long b2) {
    print(a1, b1);
    cout << " + ";
    print(a2, b2);
    cout << " = ";
    long a3 = a1 * b2 + a2 * b1;
    long b3 = b1 * b2;
    //化简到最简形式，非带分数形式
    long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    print(a3, b3);
    cout << endl;
}
void subtract(long a1, long b1, long a2, long b2) {
    print(a1, b1);
    cout << " - ";
    print(a2, b2);
    cout << " = ";
    long a3 = a1 * b2 - a2 * b1;
    long b3 = b1 * b2;
    //化简到最简形式，非带分数形式
    long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    print(a3, b3);
    cout << endl;
}
void multiply(long a1, long b1, long a2, long b2) {
    print(a1, b1);
    cout << " * ";
    print(a2, b2);
    cout << " = ";
    long a3 = a1 * a2;
    long b3 = b1 * b2;
    //化简到最简形式，非带分数形式
    long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    print(a3, b3);
    cout << endl;
}
void divide(long a1, long b1, long a2, long b2) {
    print(a1, b1);
    cout << " / ";
    print(a2, b2);
    cout << " = ";
    if (a2 == 0) {
        cout << "Inf";
    }
    else if (a2 < 0) {
        long a3 = -1 * a1 * b2;
        long b3 = -1 * b1 * a2;
        //化简到最简形式，非带分数形式
        long gcd3 = abs(gcd(a3, b3));
        a3 /= gcd3;
        b3 /= gcd3;
        print(a3, b3);
    }
    else {
        long a3 = a1 * b2;
        long b3 = b1 * a2;
        //化简到最简形式，非带分数形式
        long gcd3 = abs(gcd(a3, b3));
        a3 /= gcd3;
        b3 /= gcd3;
        print(a3, b3);
    }
    cout << endl;
}
int main() {
    long a1, b1, a2, b2;
    long c1 = 0, c2 = 0;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    //化简到最简形式，非带分数形式
    long gcd1 = abs(gcd(a1, b1));
    a1 /= gcd1;
    b1 /= gcd1;
    //化简到最简形式，非带分数形式
    long gcd2 = abs(gcd(a2, b2));
    a2 /= gcd2;
    b2 /= gcd2;

    add(a1, b1, a2, b2);
    subtract(a1, b1, a2, b2);
    multiply(a1, b1, a2, b2);
    divide(a1, b1, a2, b2);
    return 0;
}