#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void change(int &x){
    if(x == 0){
        x=1 ; 
    }else{
        x = 0 ; 
    }
}

int main()
{
    // vector<string> output = {"abc", "def", "ghi"};
    // // cout << typeid(output.size()).name() << endl;
    // // cout << typeid('a').name() << endl;

    // // cout << output[2][1] << endl;
    // int arr[5];
    // memset(arr, sizeof(arr)*5, 0);
    // for(int i = 0; i < 5;i++){
    //     cout << arr[i] << endl;
    // }
    // cout << ~0 << endl;
    // if(~0 == 1) {
    //     cout << "yes";
    // }
    // else {
    //     cout << "no";
    // }
    int y = 1;
    if(y & (y = 2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}