#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool divided = false;
    for(int i = 0; i < n; i++){
        if( n % 2 == 0 ){
            divided = true;
            break;
        }
    }   
    if(divided){
        cout << "Not Prime " << endl;
    }
    else{
        cout << "Prime " << endl;
    }
    return 0;
}