#include <iostream>
using namespace std;

int main(){
    int a;
    char c;
    a = 1990;
    c = a;
    cout << c << endl;

    c = '0';
    a = c;
    cout << a << endl;

    float f = 1.2;
    a = f;
    cout << a << endl;

    int  i = 10;
    char y = 'a';
    int z = i + y;
    char x = i + y;
    cout << x << endl;
    cout << z << endl;

    char m = 74;
    cout << m << endl;
    return 0;
}