#include <bits/stdc++.h>
// Recursion, * = added for Memoization
// int f(int i, int j, vector<vector<int>> &dp){
//     if(i == 0 && j == 0){
//         return 1;
//     }
//     if(i < 0 || j < 0){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int up = f(i - 1, j, dp);
//     int down = f(i, j - 1, dp);
//     return dp[i][j] = up + down;
// }

int uniquePaths(int m, int n) {
    // Write your code here.
    // Recursion.
//     return f(m - 1, n - 1);
    // Recursion and Memoisation
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return f(m - 1, n - 1, dp);
    
    // Tabulation
//     vector<vector<int>> dp(m, vector<int> (n, -1));
//     dp[0][0] = 1;
    // Bottom up approach
//     for(int i = 0;i < m;i++){
//         for(int j = 0;j < n;j++){
//             if(i == 0 && j == 0){ dp[0][0] = 1; continue;}
//             int up = 0, left = 0;
//             if(i > 0)
//                 up = dp[i - 1][j];
//             if(j > 0)
//                 left = dp[i][j - 1];
//             dp[i][j] = left + up;
//         }
//     }
//     return dp[m - 1][n - 1];
    
    // Space Optimise it
    vector<int> prev(n, 0);
    for(int i = 0;i < m;i++){
        vector<int> curr(n, 0);
        for(int j = 0;j < n;j++){
            if(i == 0 && j == 0) {curr[0] = 1; continue;}
            curr[j] = 0;
            // left
            if(j > 0)
                curr[j] += curr[j - 1];
            // down
            if(i > 0)
                curr[j] += prev[j];
        }
        prev = curr;
    }
    return prev[n - 1];
}