#include <bits/stdc++.h>
using namespace std;

bool comp(int &num1, int &num2){
    if(num1 % 2 == 1 || num2 % 2 == 1){
        if(num1 > num2 && num1&1 && num2&1) return false;
        if((num1&1) == 0 && num2&1) return false;
        return true;
    }
    else if(num1 < num2) return true;
    return false;
}

int main(){
    // vector<string> ans = {"flower","flow","flight"};
    // sort(begin(ans), end(ans));
    // for(auto str : ans){
    //     cout << str << endl;
    // }
    vector<int> arr = {1, 6, 4, 5, 3, 2};
    sort(arr.begin(), arr.end(), comp);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}