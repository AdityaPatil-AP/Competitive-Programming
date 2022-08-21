#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vc = vector<char>;
using vvc = vector<vc>;

int mod = 1e9 + 7;

int f(int i, int j, int *x, int *y, vector<vector<int>> &dp){
    // Base Case
    if(i == 0){
        if(j >= x[0] && j <= y[0]){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Explorations
    int ans = 0;
    for(int ii = x[i];ii <= y[i];ii++){
        if(j - ii >= 0){
            ans = (ans + f(i - 1, j - ii, x, y, dp))%mod;
        }
    }
    return dp[i][j] = ans;
}

void work(){
    // Dish Distribution
    // In these constraints dp answer is possible,

    // int n, m;
    // cin >> n >> m;
    // int x[m], y[m];
    // for(int i = 0;i < m;i++){
    //     cin >> x[i] >> y[i];
    // }
    // // due to overlapping sub - Problems - Memoise it
    // vector<vector<int>> dp(m, vector<int>(n + 1, -1));
    // cout << f(m - 1, n, x, y, dp) << endl;

    // Tabulation Way
    int n, m;
    cin >> n >> m;
    int x[m], y[m];
    for(int i = 0;i < m;i++){
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    // Base Case
    for(int i = x[0];i <= y[0] && i <= n;i++) dp[0][i] = 1;
    // For loops
    for(int i = 1;i < m;i++){
        for(int j = 0;j <= n;j++){
            int ans = 0;
            for(int ii = x[i]; ii <= y[i];ii++){
                if(j - ii >= 0){
                    ans = (ans + dp[i - 1][j - ii])%mod;
                }
            }
            dp[i][j] = ans;
        }
    } 
    cout << dp[m - 1][n] << endl;
}

int main(){
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


