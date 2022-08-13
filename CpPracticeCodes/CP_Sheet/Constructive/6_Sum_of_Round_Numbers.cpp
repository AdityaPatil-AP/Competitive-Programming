#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> ans;
    int power = 1;
    while(n){
        if(n % 10 > 0){
            ans.push_back((n % 10) * power);
        }
        n /= 10;
        power *= 10;
    }
    cout << ans.size() << endl;
    for(auto num : ans){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


