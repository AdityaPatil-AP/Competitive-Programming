#include <iostream>
using namespace std;

int factorial(int n){
    // Base Case
    if(n == 0){
        return 1;
    }
    // Induction Hypothesis
    int smallOutput = factorial(n - 1);
    // Induction Step
    return n * smallOutput;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}