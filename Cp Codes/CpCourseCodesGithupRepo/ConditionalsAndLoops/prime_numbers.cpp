#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter n : " << endl;
    cin >> n; 
    int d = 2;
    bool divided = false;
    while(d < n){
        if(n % d == 0){
            divided = true;
            cout << "Not Prime " << endl;
        }
        d++;
    }   
    if(!divided){
        cout << "Prime Number " << endl;
    }

    return 0;
}