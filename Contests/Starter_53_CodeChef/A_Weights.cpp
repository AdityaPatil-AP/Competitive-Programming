#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int


void work(){
    // A. Weights
    int w;
    cin >> w;
    vector<int> arr(3, 0);
    for(int i = 0;i < 3;i++){
        cin >> arr[i];
    }
    vector<vector<bool>> dp(3, vector<bool> (w + 1, false));
    if(arr[0] <= w){
        dp[0][arr[0]] = true;
    }
    for(int i = 0;i <= 2;i++){
        dp[i][0] = true;
    }
    // cout << "hello" << endl;
    for(int i = 1;i <= 2;i++){
        for(int j = 0;j <= w;j++){
            bool not_take = dp[i - 1][j];
            bool take = false;
            if(arr[i] <= w){
                take = dp[i - 1][w - arr[i]];
            }
            dp[i][j] = (take | not_take);
        }
    }
    (dp[2][w] == true) ? cout << "YES" : cout << "NO";
    cout << endl;
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