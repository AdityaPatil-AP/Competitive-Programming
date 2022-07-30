#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;

    if(n % 2 == 0){
        cout << "The Entered no. is even" << endl;
    }
    else{
        cout << "The Entered no. is odd" << endl;
    }
    
    return 0;
}