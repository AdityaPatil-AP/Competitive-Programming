#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define ll long long int

int main(){
    int arr[5][5];
    int i,j;
    for(i = 0; i < 5;i++){
       int a;
        for(j = 0;j < 5;j++){
            cin >> a;
            if(a == 1){
                break;
            }
        }
        if(a == 1){
            break;
         }
    }
    cout << (abs(2 - i) + abs(2 - j)) << endl;
}