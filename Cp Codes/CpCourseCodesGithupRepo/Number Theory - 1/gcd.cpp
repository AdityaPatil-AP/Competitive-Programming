#include <iostream>
using namespace std;

int gcd(int a, int b){
    // Special Case
    if(a < b){
        return gcd(b, a);
    }

    // Base Case
    if(b == 0){
        return a;
    }

    // Answer step applying Euclid's Algorithm
    return gcd(b, a%b);
}

int main(){
    int a = 10;
    int b = 30;
    cout << "GCD is : " << gcd(a, b) << endl;
    return 0;
}