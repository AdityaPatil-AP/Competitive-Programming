#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0;i < int(n);i++)

void work(){
    // My Successful Attempt
    // int n;
    // cin >> n;
    // int curr = 9;
    // stack<int> st;
    // while(1){
    //     if(n <= curr){
    //         st.push(n);
    //         break;
    //     }
    //     st.push(curr);
    //     n -= curr;
    //     curr--;
    // }
    // while(!st.empty()){
    //     cout << st.top();
    //     st.pop();
    // }
    // cout << endl;

    // Editor Solution
    int s;
    cin >> s;
    string ans;
    for(int i = 9;i >= 1;i--){
        if(s >= i){
            ans = char(i + '0') + ans;
            s -= i;
        }
    }
    cout << ans << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}