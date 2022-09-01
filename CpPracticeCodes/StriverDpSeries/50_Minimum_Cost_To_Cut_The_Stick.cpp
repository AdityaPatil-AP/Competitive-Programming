#include <bits/stdc++.h>
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    // Explorations
    int mini = 1e9;
    for(int k = i;k <= j;k++){
        int cost = (arr[j + 1] - arr[i - 1]) + f(i, k - 1, arr, dp) + f(k + 1, j,arr, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
//     cuts.push_back(n);
//     cuts.insert(cuts.begin(), 0);
//     sort(cuts.begin(), cuts.end());
//     vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
//     return f(1, c, cuts, dp);
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    // Base Case;
    for(int i = 0;i <= c;i++){
        for(int j = i + 1;j <= c;j++){
            dp[i][j] = 0;
        }
    }
    for(int i = c; i >= 1;i--){
        for(int j = i;j <= c;j++){
            int mini = 1e9;
            for(int k = i;k <= j;k++){
                int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}