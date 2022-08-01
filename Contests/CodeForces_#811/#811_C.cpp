#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    int curr = 9;
    stack<int> st;
    while(1){
        if(n <= curr){
            st.push(n);
            break;
        }
        st.push(curr);
        n -= curr;
        curr--;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
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