#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int

int f(int i, int j, int *c, int *p, int *t, vector<vector<int>> &dp){
    // BAse Case
    if(i == 0){
        if(j >= t[0]){
            return (p[0] * c[0]);
        }
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Exploration
    int not_take = f(i - 1, j, c, p, t, dp);
    int take = INT_MIN;
    if(j >= t[i]){
        take = (c[i] * p[i]) + f(i - 1, j - t[i], c, p, t, dp);
    }
    return dp[i][j] = max(take, not_take);
}

void work(){
    // Polo the Penguin and the test
    // int n, t;
    // cin >> n >> t;
    // int c[n], p[n], T[n];
    // for(int i = 0;i < n;i++){
    //     cin >> c[i] >> p[i] >> T[i];
    // }
    // // Memoise it
    // vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    // cout << f(n - 1, t, c, p, T, dp) << endl;

    // Tabulation
    // int n, t;
    // cin >> n >> t;
    // int c[n], p[n], T[n];
    // for(int i = 0;i < n;i++){
    //     cin >> c[i] >> p[i] >> T[i];
    // }
    // vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    // // Base Case
    // if(T[0] <= t)
    //     for(int i = T[0];i <= t;i++)
    //         dp[0][i] = (p[0] * c[0]);

    // // 
    // for(int i = 1;i < n;i++){
    //     for(int tt = 0;tt <= t;tt++){
    //         int not_take = dp[i - 1][tt];
    //         int take = INT_MIN;
    //         if(tt >= T[i]){
    //             take = (c[i] * p[i]) + dp[i - 1][tt - T[i]];
    //         }
    //         dp[i][tt] = max(take, not_take);
    //     }
    // }
    // cout << dp[n - 1][t] << endl;

    // Space Optimisation - 1d array
    int n, t;
    cin >> n >> t;
    int c[n], p[n], T[n];
    for(int i = 0;i < n;i++){
        cin >> c[i] >> p[i] >> T[i];
    }
    vector<int> prev(t + 1, 0);
    // Base Case
    if(T[0] <= t)
        for(int i = T[0];i <= t;i++)
            prev[i] = (p[0] * c[0]);

    // 
    for(int i = 1;i < n;i++){
        for(int tt = t;tt >= 1;tt--){
            int not_take = prev[tt];
            int take = INT_MIN;
            if(tt >= T[i]){
                take = (c[i] * p[i]) + prev[tt - T[i]];
            }
            prev[tt] = max(take, not_take);
        }
    }
    cout << prev[t] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


