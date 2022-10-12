#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> ans = {"flower","flow","flight"};
    sort(begin(ans), end(ans));
    for(auto str : ans){
        cout << str << endl;
    }
    return 0;
}