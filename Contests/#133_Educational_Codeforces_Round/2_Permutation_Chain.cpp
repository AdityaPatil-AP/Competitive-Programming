#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int

void work(){
    int n;
    cin >> n;
    // vector<vector<int>> vec(n + 1, vector<int> (n + 1, 0));
    cout << n << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                cout << 1 << " ";
            }
            else if(j < i){
                cout << j + 1 << " ";
            }
            else{
                cout << j << " "; 
            }
        }
        cout << endl;
    }
    return;
}

int32_t main(){
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