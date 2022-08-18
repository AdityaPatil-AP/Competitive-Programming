#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    // Base Case
    if(i < 0 || j < 0){
        return -1e8;
    }
    if(i == 0 && j == 0){
        return grid[0][0];
    }
    if(dp[i][j] != -1e8){
        return dp[i][j];
    }

    //Explorations;
    int up = f(i - 1, j, grid, dp) + grid[i][j];
    int left = f(i, j - 1, grid, dp) + grid[i][j]; 
    return dp[i][j] = max(up, left);
}

void work(){
    // Magic Rankings
    // int n;
    // cin >> n;
    // vector<vector<int>> grid(n, vector<int>(n, 0));
    // for(int i = 0;i < n;i++){
    //     for(int j = 0;j < n;j++){
    //         cin >> grid[i][j];
    //     }
    // }
    // vector<vector<int>> dp(n, vector<int>(n, -1e8));
    // double sum = f(n - 1, n - 1, grid, dp);
    // double ans = (double)sum/(double)(2*n - 3);
    // ((ans >= 0) ? (cout << fixed << setprecision(6) << ans << endl) : (cout << "Bad Judges" << endl));


    // Tabulation Format
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //Base Case
    for(int i = 0;i <= n;i++) dp[i][0] = -100000000;
    for(int i = 0;i <= n;i++) dp[0][i] = -100000000;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1 && j == 1){
                dp[i][j] = grid[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
    }
    double sum = dp[n][n];
    double ans = (double)sum/(double)(2*n - 3);
    ((ans >= 0) ? (cout << fixed << setprecision(6) << ans << endl) : (cout << "Bad Judges" << endl));


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


