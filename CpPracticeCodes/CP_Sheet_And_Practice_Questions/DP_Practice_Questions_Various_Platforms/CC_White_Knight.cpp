#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int i, int j, int n, vector<vector<char>> &board, vector<vector<int>> &dp){
    // Base Case
    if(j == n - 1){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    vector<pair<int, int>> v1 = {{-2,1}, {-1, 2}, {1, 2}, {2, 1}};
    // Explorations
    int maxi = INT_MIN;
    for(int ind = 0;ind <= 3;ind++){
        int inew = i + v1[ind].first;
        int jnew = j + v1[ind].second;
        if(inew < n && inew >= 0 && jnew < n){
            if(board[inew][jnew] == 'P'){
                maxi = max(maxi, 1 + f(inew, jnew, n, board, dp));
            }
            else{
                maxi = max(maxi, f(inew, jnew, n, board, dp));
            }
        }
    }
    return dp[i][j] = maxi;
}

void work(){
    // Editor Solution
    // int n;
    // cin >> n;
    // vector<vector<char>> board(n, vector<char> (n));
    // int ik, jk;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // for(int i = 0;i < n;i++){
    //     for(int j = 0;j < n;j++){
    //         cin >> board[i][j];
    //         if(board[i][j] == 'K'){
    //             ik = i;
    //             jk = j;
    //         }
    //     }
    // }
    // cout << f(ik, jk, n, board, dp) << endl;

    // Tabulation way
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char> (n));
    int ik, jk;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> board[i][j];
            if(board[i][j] == 'K'){
                ik = i;
                jk = j;
            }
        }
    }
    // base case
    vector<pair< int, int>> v1 = {{-2,1}, {-1, 2}, {1, 2}, {2, 1}};
    for(int i = 0;i < n;i++) dp[i][n - 1] = 0;
    int maxi = INT_MIN;
    for(int i = ik;i < n;i++){
        for(int j = jk;j < n;j++){
            for(int ind = 0;ind <= 3;ind++){
                int inew = i + v1[ind].first;
                int jnew = j + v1[ind].second;
                if(inew < n && inew >= 0 && jnew < n){
                    if(board[inew][jnew] == 'P'){
                        maxi = max(maxi, 1 + f(inew, jnew, n, board, dp));
                    }
                    else{
                        maxi = max(maxi, f(inew, jnew, n, board, dp));
                    }
                }
            }
            dp[i][j] = maxi;
        }
    }
    cout << dp[ik][jk] << endl;
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


